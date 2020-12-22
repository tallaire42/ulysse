#include "../../../includes/ulysse.h"

static	int	change_path_branch(char *filename)
{
	char	**txt;
	char	*path;
	char	*tmp;

	txt = NULL;
	path = NULL;
	tmp = NULL;
	if (chdir(EXEPATH))
		return (-1);
	if (chdir(SAVE))
		return (-1);
	if (!(txt = get_file(filename)))
		return (-1);
	if (chdir(txt[0]))
		return (-1);
	free_get_file(txt);
	return (0);
}

int		rm(t_env *env)
{
	char	**txt;

	txt = NULL;
	if (env->av.argc < 3)
		return (error_rm_av_missing(env));
	if (change_path_branch(DATAFILE))
		return (error_reinstall(env));
	if (!(txt = get_file(DATAFILE)))
		return (error_reinstall(env));
	if (!does_rule_exist(env->av.two, txt))
		return (error_rm_wrong_rule(env));
	
//	ft_printf("%s\n", getcwd(NULL, 1024));
	return (0);
}
