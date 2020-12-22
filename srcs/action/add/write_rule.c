#include "../../../includes/ulysse.h"

static	void	putrules(char *string, char *file_name, char *rule, int fd)
{
	ft_putstr_fd(rule, fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(file_name, fd);
	if (string[0] != '\0')
	{
		ft_putchar_fd('\n', fd);
		ft_putstr_fd(string, fd);
	}
}

int		write_rule(char *string, char *file_name, char *rule)
{
	int	fd;

	if (unlink(DATAFILE))
		return (-1);
	if ((fd = open(DATAFILE, O_CREAT, MODE_FILE) < 0))
		return (-1);
	if (close(fd))
		return (-1);
	if ((fd = open(DATAFILE, O_WRONLY)) < 0)
		return (-1);
	putrules(string, file_name, rule, fd);
	return (0);
}
