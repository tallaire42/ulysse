#include "../../includes/elec.h"

/*
** Tell if the rule match with the second argument
*/

static	int	match_rule(t_env *env, char *rule)
{
	int	i;

	i = 0;
	while (rule[i] && env->av.three[i])
	{
		if (rule[i] != env->av.three[i])
			return (-1);
		++i;
	}
	if (rule[i] != '\0' || env->av.three[i] != '\0')
		return (-1);
	return (1);
}

/*
** Give the index of the rule
*/

int		get_index(t_env *env)
{
	int	i;

	i = 0;
	while (env->data.rules[i])
	{
		if (match_rule(env, env->data.rules[i]) > 0)
			return (i);
		++i;
	}
	free_ulysse(env, 4);
	return (at_error("The rule doesn't exist"));
}
