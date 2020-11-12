#include "../../includes/elec.h"

int		start_ulysse(t_env *env)
{
	if (parser(env) < 0)
		return (-1);
	free_ulysse(env, 4);
	return (1);
}
