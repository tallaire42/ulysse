#include "../../../includes/ulysse.h"

void		help(t_env *env)
{
	int	i;

	i = 0;
	while (env->branch.rules[i])
	{
		printf("%s\n", env->branch.rules[i]);
		++i;
	}
}
