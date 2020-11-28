#include "../../../includes/ulysse.h"

int		insert_rule(t_env *env)
{
	int	fd;

	(void)env;
	fd = 0;
	if ((fd = at_open("data.uly")) <= 0)
		return (-1);
	return (0);
}
