#include "../../../includes/ulysse.h"

int		set(t_env *env)
{
	if (env->av.argc < 3)
		return (error_set_av_missing(env));
	if (init_save(env))
		return (error_set_init_save(env));
	if (init_branch(env))
		return (error_set_init_branch(env));
	if (write_branch(env))
		return (-1);
	return (0);
}
