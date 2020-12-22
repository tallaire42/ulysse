#include "../../../includes/ulysse.h"

static	char	*get_string_file(char *file)
{
	int	fd;
	char	*string;
	char	*tmp;
	char	buffer[BUFFER_SIZE];

	string = NULL;
	tmp = NULL;
	if (!(string = ft_calloc(1, 1)))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		free(string);
		return (NULL);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		tmp = string;
		if (!(string = ft_strjoin(string, buffer)))
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
	}
	return (string);
}

int		insert_rule(char *file_name, char *rule)
{
	char	*string;

	string = NULL;
	if (!(string = get_string_file(DATAFILE)))
		return (-1);
	if (write_rule(string, file_name, rule))
	{
		free(string);
		return (-1);
	}
	free(string);
	return (0);
}
