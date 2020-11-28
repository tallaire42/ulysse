#include "../../../includes/ulysse.h"

int		print(t_env *env)
{
	int	index;

	index = 0;
	if ((index = get_index(env)) < 0)
		return (-1);
	if (print_file(env->branch.path[index]) < 0)
	{
		free_ulysse(env, 4);
		return (-1);
	}
	return (1);
}
