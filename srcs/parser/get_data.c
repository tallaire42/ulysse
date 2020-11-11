#include "../../includes/elec.h"

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

static	int	alloc_rules_and_def(t_env *env, size_t size)
{
	if (!(env->data.path = (char **)calloc(size + 1, sizeof(char *))))
	{
		printf("Error\nAlloc memory failed in %s", env->av.one);
		return (-1);
	}
	if (!(env->data.rules = (char **)calloc(size + 1, sizeof(char *))))
	{
		free(env->data.def);
		printf("Error\nAlloc memory failed in %s", env->av.one);
		return (-1);
	}
	return (1);
}

static	size_t	how_many_rules(t_env *env)
{
	size_t	nb_rules;
	int	i;

	nb_rules = 0;
	i = 0;
	while (env->data.txt[i] != NULL)
	{
		while (env->data.txt[i] != NULL && env->data.txt[i][0] == '\0')
			++i;
		if (env->data.txt[i] == NULL)
			break ;
		if (ft_isalpha(env->data.txt[i][0]) > 0)
			++nb_rules;
		++i;
	}
	if (nb_rules == 0)
		printf("Error\n%s is empty", env->av.one);
	return (nb_rules);
}

void		*get_data(t_env *env)
{
	int	i;
	int	count;
	size_t	nb_rules;

	i = 0;
	count = 0;
	if ((nb_rules = how_many_rules(env)) < 0)
		return (free_elec(env, 3));
	if (alloc_rules_and_def(env, nb_rules) < 0)
		return (free_elec(env, 3));
	while (env->data.txt[i] != NULL)
	{
		while (env->data.txt[i] != NULL && env->data.txt[i][0] == '\0')
			++i;
		if (env->data.txt[i] == NULL)
			break ;
		if (get_rules_and_def(env, env->data.txt[i], count) < 0)
			return (free_elec(env, 4));
		++count;
		++i;
	}
	return (env->data.rules);
}
