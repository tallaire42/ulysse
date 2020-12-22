#include "../../../../includes/ulysse.h"

int		error_unset_av_missing(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("The argument %sBRANCH%s is missing\n", GREEN, NC);
	ft_printf("To use %sunset%s action, ", GREEN, NC);
	ft_printf("please write your command as follow :\n\n");
	ft_printf("uly unset %sbranch%s\n", GREEN, NC);
	return (-1);
}

