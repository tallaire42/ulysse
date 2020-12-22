#include "../includes/libft.h"

void	free_get_file(char **txt)
{
	int	i;

	i = 0;
	while (txt && txt[i])
	{
		free(txt[i]);
		++i;
	}
	free(txt);
	txt = NULL;
}

