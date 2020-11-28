#include "../../includes/ulysse.h"

static	void	free_txt(char **txt)
{
	int	i;

	i = 0;
	while (txt && txt[i])
	{
		free(txt[i]);
		++i;
	}
	free(txt);
	txt = NULL;
}

static	void	free_av(t_env *env)
{
	free(env->av.one);
	env->av.one = NULL;
	if (env->av.two != NULL)
		free(env->av.two);
	env->av.two = NULL;
	if (env->data.path != NULL)
		free(env->data.path);
	env->data.path = NULL;
}

static	void	free_data(t_env *env)
{
	int	i;

	i = 0;
	while (env->branch.rules[i])
	{
		free(env->branch.path[i]);
		free(env->branch.rules[i]);
		++i;
	}
	free(env->branch.rules);
	env->branch.rules = NULL;
	free(env->branch.path);
	env->branch.path = NULL;
}

void		*free_ulysse(t_env *env, int end)
{
	int	i;

	i = 0;
	if (++i < end)
		free_av(env);
	if (++i < end)
		free_txt(env->branch.txt);
	if (++i < end)
		free_data(env);
	return (NULL);
}
