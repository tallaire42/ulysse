#include "../../../includes/ulysse.h"

static	int	create_datafile(t_env *env)
{
	int	fd;

	fd = 0;
	if (chdir(env->av.two))
		return (-1);
	if ((fd = open(DATAFILE, O_CREAT, MODE_FILE)) < 0)
		return (-1);
	if (close(fd))
		return (-1);
	if (!opendir(FILES))
	{
		if (errno == ENOENT)
		{
			if (mkdir(FILES, MODE_DIR))
				return (-1);
		}
		else
			return (-1);
	}
	if (chdir(".."))
		return (-1);
	return (0);
}

int		init_branch(t_env *env)
{
	int	ret;

	ret = 0;
	if (chdir(SAVE))
		return (-1);
	if (!opendir(env->av.two))
	{
		if (errno != ENOENT)
			return (-1);
		if (mkdir(env->av.two, MODE_DIR))
			return (-1);
		if (create_datafile(env))
			return (-1);
		if (chdir(".."))
			return (-1);
		return (0);
	}
	if (create_datafile(env))
		return (-1);
	if (chdir(".."))
		return (-1);
	return (0);
}
