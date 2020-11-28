#include "../../includes/ulysse.h"

/*
** Check a line of .elec extension file.
**
** if the first argument has a none alpha character or a '_',
** the function return an error.
**
** if there is a space (' ') inside the second argument,
** the function return an error.
*/

static	int	check_this_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (ft_isalpha(line[i]) <= 0 && line[i] != '_')
			return (-1);
		++i;
	}
	if (line[i] != ' ')
		return (-1);
	while (line[i] == ' ')
		++i;
	while (line[i] != ' ' && line[i] != '\0')
		++i;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (-1);
		++i;
	}
	return (0);
}

int		check_data(char **txt)
{
	int	i;

	i = 0;
	while (txt[i] != NULL)
	{
		while (txt[i] != NULL && txt[i][0] == '\0')
		{
			++i;
			if (txt[i] == NULL)
				break ;
		}
		if (txt[i] == NULL)
			break ;
		if (check_this_line(txt[i]))
		{
			printf("%sError%s\nWrong data in data.uly\n", RED, NC);
			printf("(line : %d)", i + 1);
			return (-1);
		}
		++i;
	}
	return (0);
}
