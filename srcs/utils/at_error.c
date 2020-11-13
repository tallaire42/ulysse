# include "../../includes/ulysse.h"

int	at_error(char *str)
{
	printf("Error\n%s", str);
	return (-1);
}

char	*at_err_null(char *str)
{
	printf("Error\n%s", str);
	return (NULL);
}
