#include "../../../includes/ulysse.h"

static	int	is_not_a_branch(char *txt, char *branch)
{
	int	i;

	i = 0;
	while (txt && branch && txt[i] && txt[i] != ' ' && branch[i])
	{
		if (txt[i] != branch[i])
			return (0);
		++i;
	}
	if (branch[i] != '\0')
		return (0);
	if (txt[i] != ' ' && txt[i] != '\0')
		return (0);
	return (-1);
}

static	int	is_branch_exist(char **txt, char *branch)
{
	int	i;

	i = 0;
	while (txt && txt[i])
	{
		if (is_not_a_branch(txt[i], branch))
			return(0);
		++i;
	}
	return (-1);
}

static	int	rm_branch(char **txt, char *branch)
{
	int	fd;
	int	i;

	i = 0;
	if (unlink(DATAFILE))
		return (-1);
	if ((fd = open(DATAFILE, O_CREAT, MODE_FILE)) < 0)
		return (-1);
	if (close(fd))
		return (-1);
	if ((fd = open(DATAFILE, O_WRONLY)) < 0)
		return (-1);
	while (txt && txt[i])
	{
		if (!is_not_a_branch(txt[i], branch))
		{
			if (i != 0)
				ft_putchar_fd('\n', fd);
			ft_putstr_fd(txt[i], fd);
		}
		++i;
	}
	if (close(fd))
		return (-1);
	return (0);
}

int		rm_branch_datafile(t_env *env)
{
	char	**txt;

	txt = NULL;
	if (chdir(SAVE))
		return (error_reinstall(env));
	if (!(txt = get_file(DATAFILE)))
		return (error_reinstall(env));
	if (is_branch_exist(txt, env->av.two))
		return (error_wrong_branch(env, txt, env->av.two));
	if (rm_branch(txt, env->av.two))
		return (error_reinstall(env));
	if (chdir(".."))
		return (error_reinstall(env));
	return (0);
}
