#include "../../includes/ulysse.h"

int	error_reinstall(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n", RED, NC);
	ft_printf("Ulysse must be corrupted for some reason\n");
	ft_printf("Please reinstall Ulysse with the following command :\n\n");
	ft_printf("ulysse %sreinstall%s\n", GREEN, NC);
	return (-1);
}
