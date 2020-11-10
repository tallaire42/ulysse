#include "../../includes/elec.h"

int	at_open(char *file_name)
{
	int	fd;

	fd = 0;
	if ((fd = open(file_name, O_RDONLY)) <= 0)
	{
		printf("Error\nCan't find or open %s", file_name);
		return (-1);
	}
	return (fd);
}
