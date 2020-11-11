#include "../../includes/elec.h"

int		parser(t_env *env)
{
	char	**txt;

	txt = NULL;
	if (!(env->data.txt = get_file(env, env->av.one)))
		return (-1);
	if (check_data(env) < 0)
		return (-1);
	if (!(get_data(env)))
		return (-1);
	if ((env->print.index = get_index(env)) < 0)
		return (-1);
	return (1);
}
