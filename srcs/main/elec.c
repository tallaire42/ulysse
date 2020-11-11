#include "../../includes/elec.h"

int		start_elec(t_env *env)
{
	if (parser(env) < 0)
		return (-1);
	free_elec(env, 4);
	return (1);
}
