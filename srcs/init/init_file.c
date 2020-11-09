#include "../../includes/elec.h"

void		init_file(t_env *env)
{
	env->file.fd = 0;
	env->file.size = 0;
	env->file.txt = NULL;
}
