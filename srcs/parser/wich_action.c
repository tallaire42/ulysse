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
	return (0);
}

int		wich_action(char *av)
{
	if (!is_str(av, PRINT_ACT))
		return (PRINT);
	if (!is_str(av, HELP_ACT))
		return (HELP);
	if (!is_str(av, ADD_ACT))
		return (ADD);
	if (!is_str(av, SET_ACT))
		return (SET);
	if (!is_str(av, UNSET_ACT))
		return (UNSET);
	if (!is_str(av, LS_ACT))
		return (LS);
	if (!is_str(av, CD_ACT))
		return (CD);
	if (!is_str(av, RM_ACT))
		return (RM);
	if (!is_str(av, PRINT_ACT))
		return (PRINT);
	return (-1);
}
