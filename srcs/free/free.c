#include "../../includes/elec.h"

void		free_elec(t_env *env)
{
	free(env->av.one);
	free(env->file.txt);
}
