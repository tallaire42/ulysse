#include "../../../../includes/ulysse.h"

int		error_ls_wrong_av(t_env *env)
{
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("%s%s%s is not a valid argument for", PURPLE, env->av.two, NC);
	ft_printf(" %sls%s action\n", GREEN, NC);
	return (-1);
}
