#include "../../../includes/ulysse.h"

int		unset(t_env *env)
{
	if (env->av.argc < 3)
		return (error_unset_av_missing(env));
	if (rm_branch_datafile(env))
		return (-1);
	if (close_branch_fs(env))
		return (error_reinstall(env));
	return (0);
}
