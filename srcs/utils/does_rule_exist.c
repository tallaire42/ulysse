#include "../../includes/ulysse.h"

static	int	match_rule(char *txt, char *rule)
{
	int	i;

	i = 0;
	while (txt && txt[i] && txt[i] != ' ' && rule[i])
	{
		if (txt[i] != rule[i])
			return (-1);
		++i;
	}
	if (txt[i] != ' ' && txt[i] != '\0')
		return (-1);
	if (rule[i])
		return (-1);
	return (0);
}

int		does_rule_exist(char *rule, char **txt)
{
	int	i;

	i = 0;
	while (txt && txt[i] && rule)
	{
		if (!match_rule(txt[i], rule))
			return (-1);
		++i;
	}
	return (0);
}
