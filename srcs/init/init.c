#include "../../includes/elec.h"

static	void	init_print(t_env *env)
{
	env->print.index = 0;
	env->print.fd = 0;
}

void	init(t_env *env)
{
	init_print(env);
	init_file(env);
}
