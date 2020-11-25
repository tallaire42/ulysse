#include "../../includes/ulysse.h"

int		start_ulysse(t_env *env)
{
	if (parser(env) < 0)
		return (-1);
	if (env->av.act == PRINT)
		if (print(env) < 0)
			return (-1);
	if (env->av.act == HELP)
		help(env);
	if (env->av.act == ADD)
		if (add(env) < 0)
			return (-1);
	free_ulysse(env, 4);
	return (1);
}
