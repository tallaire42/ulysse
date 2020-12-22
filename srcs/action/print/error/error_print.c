#include "../../../../includes/ulysse.h"

int		error_print_av_missing(t_env *env)
{
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("The argument %sRULE%s is missing\n", GREEN, NC);
	ft_printf("To use %sprint%s action, ", GREEN, NC);
	ft_printf("please write your command as follow :\n\n");
	ft_printf("uly print %sRULE%s\n", GREEN, NC);
	free_main_av(env);
	return (-1);
}

int		error_print_rule_doesnt_exist(t_env *env)
{
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("%s%s%s doesn't exist inthe current branch\n", PURPLE, env->av.two, NC);
	free_main_av(env);
	return (-1);
}
