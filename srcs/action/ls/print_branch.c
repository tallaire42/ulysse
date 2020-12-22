#include "../../../includes/ulysse.h"

static	void	print_txt(char **txt)
{
	int	i;

	i = 0;
	while (txt[i])
	{
		if (i == 0)
			ft_printf("%s%s%s", YELLOW, txt[i], NC);
		else
			ft_printf("%s%s%s", BLACK, txt[i], NC);
		ft_printf("\n");
		++i;
	}
}

static	int	is_str(char *branch, char *av)
{
	int	i;

	i = 0;
	while (branch[i] && av[i])
	{
		if (branch[i] != av[i])
			return (-1);
		++i;
	}
	if (branch[i] != '\0' || av[i] != '\0')
		return (-1);
	return (0);
}

int		print_branch(t_env *env)
{
	char	**txt;

	txt = NULL;
	if (is_str(BRANCH_ACT, env->av.two))
		return (error_ls_wrong_av(env));
	if (chdir(SAVE))
		return (error_reinstall(env));
	if (!(txt = get_file(DATAFILE)))
		return (error_reinstall(env));
	print_txt(txt);
	free_get_file(txt);
	if (chdir(".."))
		return (error_reinstall(env));
	return (0);
}
