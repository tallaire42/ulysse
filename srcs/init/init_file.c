#include "../../includes/ulysse.h"

void		init_file(t_env *env)
{
	env->data.size = 0;
	env->data.txt = NULL;
	env->data.rules = NULL;
	env->data.path = NULL;
	env->branch.path = NULL;
	env->av.one = NULL;
	env->av.two = NULL;
}
