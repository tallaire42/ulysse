#include "../../includes/ulysse.h"

int		parser(t_env *env)
{
	int	index;
	char	**txt;

	index = 0;
	txt = NULL;
	env->av.act = 0;
	if (!(env->data.path = wich_branch(DATAFILE)))
	{
		free_ulysse(env, 2);
		return (-1);
	}
	if (!(env->branch.txt = get_file(env->data.path)))
	{
		free_ulysse(env, 2);
		return (-1);
	}
	if (check_data(env->branch.txt))
		return (-1);
	if (!(get_data(env)))
	{
		free_ulysse(env, 3);
		return (-1);
	}
	if ((env->av.act = wich_action(env->av.one)) < 0)
	{
		free_ulysse(env, 3);
		return (-1);
	}
	return (0);
}
