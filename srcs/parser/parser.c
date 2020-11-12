#include "../../includes/elec.h"

int		parser(t_env *env)
{
	int	index;
	char	**txt;

	index = 0;
	txt = NULL;
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
	if ((index = get_index(env)) < 0)
		return (-1);
	if (print_file(env->data.path[index]) < 0)
	{
		free_ulysse(env, 4);
		return (-1);
	}
	return (1);
}
