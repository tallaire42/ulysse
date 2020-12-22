#include "../../../../includes/ulysse.h"

int		error_cd_reinstall(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s%s\n", RED, NC);
	ft_printf("Ulysse must be corrupted for some reason\n");
	ft_printf("Please reinstall Ulysse with the following command :\n\n");
	ft_printf("ulysse %sreinstall%s\n", GREEN, NC);
	return (-1);
}

int		error_cd_av_missing(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("The %sBRANCH%s argument is missing\n", GREEN, NC);
	ft_printf("To use %scd%s action, ", GREEN, NC);
	ft_printf("please write your command as follow :\n\n");
	ft_printf("uly cd %sBRANCH%s\n", GREEN, NC);
	return (-1);
}

int		error_cd_wrong_av(t_env *env, char **txt)
{
	int	i;

	i = 0;
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("%s%s%s branch does not exist\n", PURPLE, env->av.two, NC);
	ft_printf("Currently, the existing branch are :\n\n");
	while (txt && txt[i])
	{
		if (i == 0)
			ft_printf("%s%s%s", YELLOW, txt[i], NC);
		else
			ft_printf("\n%s%s%s", BLACK, txt[i], NC);
		++i;
	}
	ft_printf("\n");
	free_get_file(txt);
	return (-1);
}

