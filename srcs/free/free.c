#include "../../includes/elec.h"

char		**free_get_file(char **txt, size_t *size)
{
	size_t	i;

	i = 0;
	if (txt == NULL)
		return (NULL);
	while (i < *size)
	{
		free(txt[i]);
		++i;
	}
	free(txt);
	txt = NULL;
	size = 0;
	return (NULL);
}

static	void	free_av_one(t_env *env)
{
	free(env->av.one);
	env->av.one = NULL;
}

void		*free_elec(t_env *env, int end)
{
	int	i;

	i = 0;
	if (++i < end)
		free_av_one(env);
	if (++i < end)
		env->data.txt =
		free_get_file(env->data.txt, &env->data.size);
	return (NULL);
}
