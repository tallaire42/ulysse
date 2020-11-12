#include "../../includes/elec.h"

int		print_file(char *path_file)
{
	int	fd;
	char	*line;

	line = NULL;
	if ((fd = at_open(path_file)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	return (1);
}
