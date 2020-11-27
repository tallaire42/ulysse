#include "../../../includes/ulysse.h"

char		*get_file_name(char *path)
{
	char	*file_name;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	file_name = NULL;
	while (path[i] && (path[i] == '.' || path[i] == '/'))
		++i;
	if (!(file_name = ft_calloc(ft_strlen(path + i) + 1, sizeof(char))))
	{
		printf("Error\nCan't get file name of %s\n", path);
		return (NULL);
	}
	while (path[i])
	{
		file_name[j] = path[i];
		++i;
		++j;
	}
	file_name[j] = '\0';
	return (file_name);
}
