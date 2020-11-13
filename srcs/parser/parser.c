#include "../../includes/ulysse.h"

int		parser(t_env *env)
{
	int	index;
	char	**txt;

	index = 0;
	txt = NULL;
	env->av.act = 0;
	if (!(env->data.txt = get_file(env->av.one)))
	{
		free_ulysse(env, 2);
		return (-1);
	}
	if (check_data(env) < 0)
		return (-1);
	if (!(get_data(env)))
	{
		free_ulysse(env, 3);
		return (-1);
	}
	if ((env->av.act = wich_action(env->av.two)) < 0)
	{
		free_ulysse(env, 3);
		return (-1);
	}
	return (1);
}
