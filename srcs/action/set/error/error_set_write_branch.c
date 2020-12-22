#include "../../../../includes/ulysse.h"

int	error_set_branch_exist(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("%s%s%s already exists\n", PURPLE, env->av.two, NC);
	return (-1);
}

int	error_set_write_branch(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("Ulysse program might be corrupted\n");
	ft_printf("Please %sREINSTALL%s ulysse with the ", GREEN, NC);
	ft_printf("following command : \n\n");
	ft_printf("uly reinstall\n");
	return (0);
}

