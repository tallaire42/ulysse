#include "../../../includes/ulysse.h"

void		help(t_env *env)
{
	int	i;

	i = 0;
	while (env->data.rules[i])
	{
		printf("%s\n", env->data.rules[i]);
		++i;
	}
}
