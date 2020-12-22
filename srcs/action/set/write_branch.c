#include "../../../includes/ulysse.h"

static	int	datafile_cpy(char **txt, char *branch)
{
	int	i;
	int	fd;

	i = 0;
	if ((fd = open(DATAFILE, O_CREAT, MODE_FILE)) < 0)
		return (-1);
	if (close(fd))
		return (-1);
	if ((fd = open(DATAFILE, O_WRONLY)) < 0)
		return (-1);
	ft_putstr_fd(branch, fd);
	while (txt[i])
	{
		ft_putchar_fd('\n', fd);
		ft_putstr_fd(txt[i], fd);
		++i;
	}
	if (close(fd))
		return (-1);
	return (0);
}

static	int	match_rule(char *txt, char *branch)
{
	int	i;

	i = 0;
	while (txt[i] && branch[i])
	{
		if (txt[i] != branch[i])
			return (-1);
		++i;
	}
	if (txt[i] != '\0' || branch[i] != '\0')
		return (-1);
	return (1);
}

static	int	err_free_txt(char **txt)
{
	free_get_file(txt);
	chdir("..");
	return (-1);
}

static	int	is_branch_exist(char **txt, char *branch)
{
	int	i;

	i = 0;
	while (txt[i])
	{
		if (match_rule(txt[i], branch) > 0)
			return (err_free_txt(txt));
		++i;
	}
	return (0);
}

int		write_branch(t_env *env)
{
	char	**txt;

	txt = NULL;
	if (chdir(SAVE))
		return (error_set_write_branch(env));
	if (!(txt = get_file(DATAFILE)))
		return (error_set_write_branch(env));
	if (is_branch_exist(txt, env->av.two))
		return (error_set_branch_exist(env));
	if (unlink(DATAFILE))
		return (err_free_txt(txt));
	if (datafile_cpy(txt, env->av.two))
		return (err_free_txt(txt));
	free_get_file(txt);
	if (chdir(".."))
		return (error_set_write_branch(env));
	return (0);
}
