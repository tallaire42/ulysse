#include "../../../includes/ulysse.h"

int		add(t_env *env)
{
	char	*rule;

	rule = NULL;
	if (!(rule = get_rule(env->av.three)))
	{
		return (-1);
	}
	return (1);
}
