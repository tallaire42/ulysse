#include "../../../../includes/ulysse.h"

int	error_set_av_missing(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("The argument %sBRANCH%s is missing\n", GREEN, NC);
	ft_printf("To use %sSET%s action, ", GREEN, NC);
	ft_printf("please write your command as follow :\n\n");
	ft_printf("uly set %sBRANCH%s\n", GREEN, NC);
	return (-1);
}

int	error_set_init_branch(t_env *env)
{
	(void)env;

	ft_printf("%sError%s\n\n", RED, NC);
	return (-1);
}

int	error_set_init_save(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("Ulysse program might be corrupted\n");
	ft_printf("Please %sREINSTALL%s ulysse with the ", GREEN, NC);
	ft_printf("following command : \n\n");
	ft_printf("uly reinstall\n");
	return (0);
}
