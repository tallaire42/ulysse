#include "../../../includes/ulysse.h"

int	error_ulysse_action(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("%s is an unknown action\n", env->av.one);
	ft_printf("To know wich action are available,");
	ft_printf(" please write the following command :\n\n");
	ft_printf("uly help");
	return (-1);
}
