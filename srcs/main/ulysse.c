#include "../../includes/ulysse.h"

static	int	create_files(t_env *env)
{
	int	ret;

	ret = 0;
	env->data.fd = open(DATAFILE, O_CREAT, MODE_FILE);
	if (!(env->data.path = getcwd(env->data.path, 4096)))
	{
		printf("%sError%s\n", RED, NC);
		printf("Can't find current working directory");
		return (-1);
	}
	ret = mkdir("tmp", 0);
	if (ret == 0)
	{
		if ((ret = chmod("tmp", MODE_DIR)) < 0)
		{
			printf("%sError%s\n", RED, NC);
			printf("Can't set right permission to %s", TMPDIR);
			return (-1);
		}
	}
	return (0);
}

static	int	action(t_env *env, int action)
{
	if (PRINT == action)
		if (print(env))
			return (-1);
	if (HELP == action)
		help(env);
	if (ADD == action)
		if (add(env))
			return (-1);
	if (SET == action)
		if (set(env))
			return (-1);
	return (0);
}

int		start_ulysse(t_env *env)
{
	if (create_files(env))
		return (-1);
	if (parser(env))
		return (-1);
	if (action(env, env->av.act))
		return (-1);
	free_ulysse(env, 4);
	return (0);
}
