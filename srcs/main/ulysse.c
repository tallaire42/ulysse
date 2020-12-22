#include "../../includes/ulysse.h"

static	int	action(t_env *env, int action)
{
	if (SET == action)
		if (set(env))
			return (-1);
	if (UNSET == action)
		if (unset(env))
			return (-1);
	if (LS == action)
		if (ls(env))
			return (-1);
	if (CD == action)
		if (cd(env))
			return (-1);
	if (ADD == action)
		if (add(env))
			return (-1);
	if (RM == action)
		if (rm(env))
			return (-1);
	if (PRINT == action)
		if (print(env))
			return (-1);
	return (0);
}

int		start_ulysse(t_env *env)
{
	if ((env->av.act = wich_action(env->av.one)) < 0)
		return (error_ulysse_action(env));
	if (action(env, env->av.act))
		return (-1);
	return (0);
}
