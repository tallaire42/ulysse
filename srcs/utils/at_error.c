# include "../../includes/ulysse.h"

int	at_error(char *str)
{
	printf("%sError%s\n%s", RED, NC, str);
	return (-1);
}

char	*at_err_null(char *str)
{
	printf("%sError%s\n%s", RED, NC, str);
	return (NULL);
}
