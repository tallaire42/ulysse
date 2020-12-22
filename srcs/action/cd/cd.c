#include "../../../includes/ulysse.h"

static	int	create_datafile(char **txt)
{
	int	fd;
	int	i;

	i = 0;
	if ((fd = open(DATAFILE, O_CREAT, MODE_FILE)) < 0)
		return (-1);
	if (close(fd))
		return (-1);
	if ((fd = open(DATAFILE, O_WRONLY)) < 0)
		return (-1);
	while (txt && txt[i])
	{
		if (i != 0)
			ft_putchar_fd('\n', fd);
		ft_putstr_fd(txt[i], fd);
		++i;
	}
	if (close(fd))
		return (-1);
	return (0);
}

static	int	match_branch(char *txt, char *av)
{
	int	i;

	i = 0;
	while (txt[i] && av[i])
	{
		if (av[i] != txt[i])
			return (-1);
		++i;
	}
	if (av[i] != '\0' || txt[i] != '\0')
		return (-1);
	return (0);
}

static	int	is_a_branch(char **txt, char *av)
{
	int	i;

	i = 0;
	while (txt && txt[i])
	{
		if (!match_branch(txt[i], av))
			return (0);
		++i;
	}
	return (-1);
}

int		cd(t_env *env)
{
	char	**txt;

	if (env->av.argc < 3)
		return (error_cd_av_missing(env));
	if (chdir(SAVE))
		return (error_cd_reinstall(env));
	if (!(txt = get_file(DATAFILE)))
		return (error_cd_reinstall(env));
	if (is_a_branch(txt, env->av.two))
		return (error_cd_wrong_av(env, txt));
	if (unlink(DATAFILE))
		return (error_cd_reinstall(env));
	if (!(txt = switch_branch(txt, env->av.two)))
		return (error_cd_reinstall(env));
	if (create_datafile(txt))
		return (error_cd_reinstall(env));
	free_get_file(txt);
	return (0);
}
