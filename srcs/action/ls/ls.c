#include "../../../includes/ulysse.h"

int		ls(t_env *env)
{
	if (env->av.argc == 3)
		if (print_branch(env))
			return (-1);
	return (0);
}
