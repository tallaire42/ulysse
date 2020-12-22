#include "../../includes/ulysse.h"

int	error_wrong_branch(t_env *env, char **txt, char *branch)
{
	int	i;

	i = 0;
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("%s%s%s branch does not exist\n", PURPLE, branch, NC);
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
	free_main_av(env);
	free_get_file(txt);
	return (-1);
}
