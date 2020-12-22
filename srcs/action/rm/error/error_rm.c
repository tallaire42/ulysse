#include "../../../../includes/ulysse.h"

int		error_rm_av_missing(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("The argument %sRULE%s is missing\n", GREEN, NC);
	ft_printf("To use %srm%s action, ", GREEN, NC);
	ft_printf("please write your command as follow :\n\n");
	ft_printf("uly unset %sRULE%s\n", GREEN, NC);
	return (-1);
}

int		error_rm_wrong_rule(t_env *env)
{
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("Can't find %s%s%s rule\n", GREEN, env->av.two, NC);
	return (-1);
}
