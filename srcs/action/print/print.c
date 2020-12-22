#include "../../../includes/ulysse.h"

static	char	**get_rules(void)
{
	char	**txt;

	txt = NULL;
	if (chdir(EXEPATH))
		return (NULL);
	if (chdir(SAVE))
		return (NULL);
	if (!(txt = get_file(DATAFILE)))
		return (NULL);
	if (chdir(txt[0]))
	{
		free_get_file(txt);
		return (NULL);
	}
	free_get_file(txt);
	if (!(txt = get_file(DATAFILE)))
		return (NULL);
	return (txt);
}

int		print(t_env *env)
{
	char	**txt;

	txt = NULL;
	if (env->av.argc < 3)
		return (error_print_av_missing(env));
	if (!(txt = get_rules()))
		return (error_reinstall(env));
	if (!does_rule_exist(env->av.two, txt))
		return (error_print_rule_doesnt_exist(env));
	if (chdir(FILES))
	{
		free_get_file(txt);
		return (error_reinstall(env));
	}
	if (print_file(env->av.two, txt))
		return (-1);
	return (0);
}
