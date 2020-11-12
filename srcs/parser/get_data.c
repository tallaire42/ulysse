#include "../../includes/elec.h"

void	*free_get_data(t_env *env)
{
	int	i

	i = 0;
	while (env->data.rules && env->data.rules[i])
	{
		free(env->data.rules[i]);
		++i;
	}
	free(env->data.rules);
	env->data.rules = NULL;
	i = 0;
	while (env->data.path && env->data.path[i])
	{
		free(env->data.path[i]);
		++i;
	}
	free(env->data.path);
	env->data.path = NULL;
	return (NULL);
}

static	int	get_rules_and_def(t_env *env, char *str, int j)
{
	int	i;

	i = 0;
	if (!(env->data.rules[j] = strdup_sep(str, ' ')))
		return (-1);
	env->data.rules[j + 1] = NULL;
	while (str[i] != '\0' && str[i] != ' ')
		++i;
	while (str[i] != '\0' && str[i] == ' ')
		++i;
	if (!(env->data.path[j] = strdup_sep(str + i, ' ')))
		return (-1);
	env->data.path[j + 1] = NULL;
	return (1);
}

static	char	**alloc_path(t_env *env, size_t size)
{
	char	**new;

	new = NULL;
	if (!(new = (char **)calloc(size + 1, sizeof(char *))))
	{
		free(env->data.rules);
		env->data.rules = NULL;
		printf("Error\nAlloc memory failed in %s", env->av.one);
		return (NULL);
	}
	return (new);
}

static	char	**alloc_rules(t_env *env, size_t size)
{
	char	**new;

	new = NULL;
	if (!(new = (char **)calloc(size + 1, sizeof(char *))))
	{
		printf("Error\nAlloc memory failed in %s", env->av.one);
		return (NULL);
	}
	return (new);
}

static	size_t	how_many_rules(char **txt, char *file_name)
{
	size_t	nb_rules;
	int	i;

	nb_rules = 0;
	i = 0;
	while (txt[i] != NULL)
	{
		while (txt[i] != NULL && txt[i][0] == '\0')
			++i;
		if (txt[i] == NULL)
			break ;
		if (ft_isalpha(txt[i][0]) > 0)
			++nb_rules;
		++i;
	}
	if (nb_rules == 0)
		printf("Error\n%s is empty", file_name);
	return (nb_rules);
}

void		*get_data(t_env *env)
{
	int	i;
	int	count;
	size_t	nb_rules;

	i = 0;
	count = 0;
	if ((nb_rules = how_many_rules(env->data.txt, env->av.one)) < 0)
		return (NULL);
	if (!(env->data.rules = alloc_rules(env, nb_rules)))
		return (NULL);
	if (!(env->data.path = alloc_path(env, nb_rules)))
		return (NULL);
	while (env->data.txt[i] != NULL)
	{
		while (env->data.txt[i] != NULL && env->data.txt[i][0] == '\0')
			++i;
		if (env->data.txt[i] == NULL)
			break ;
		if (get_rules_and_def(env, env->data.txt[i], count) < 0)
			return (free_get_data(env));
		++count;
		++i;
	}
	return (env->data.rules);
}
