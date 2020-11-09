#include "../../includes/elec.h"

int		parser(t_env *env)
{
	if (get_file(env) < 0)
		return (-1);
	return (1);
}
