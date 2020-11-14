#include "../../includes/ulysse.h"

static	int	is_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		++i;
	}
	return (1);
}

int		wich_action(char *av)
{
	if (is_str(av, PRINT_ACT) > 0)
		return (PRINT);
	if (is_str(av, HELP_ACT) > 0)
		return (HELP);
	return (at_error("Unknown action"));
}
