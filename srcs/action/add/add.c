#include "../../../includes/ulysse.h"

int		add(t_env *env)
{
	char	*file_path;

	if (at_open(env->av.two) <= 0)
		return (-1);
	if (check_rule(env->av.two))
		return (-1);
	if (!(file_path = get_added_path(env)))
		return (-1);
	if (insert_rule(env))
		return (-1);
	if (cpy_file(env))
		return (-1);
	return (0);
}
