#include "../../../includes/ulysse.h"

int		close_branch_fs(t_env *env)
{
	if (chdir(SAVE))
		return (-1);
	if (chdir(env->av.two))
		return (-1);
	if (rmdir(FILES))
		return (-1);
	if (unlink(DATAFILE))
		return (-1);
	if (chdir(".."))
		return (-1);
	if (rmdir(env->av.two))
		return (-1);
	if (chdir(".."))
		return (-1);
	return (0);
}
