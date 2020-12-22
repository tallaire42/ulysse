#include "../../../includes/ulysse.h"

static	int	is_datafile(void)
{
	int	fd;

	fd = 0;
	if (chdir(SAVE))
		return (-1);
	if ((fd = open(DATAFILE, O_RDONLY)) >= 0)
	{
		if (close(fd))
			return (-1);
		if (chdir(".."))
			return (-1);
		return (0);
	}
	if ((fd = open(DATAFILE, O_CREAT, MODE_FILE)) < 0)
		return (-1);
	if (close(fd))
		return (-1);
	if (chdir(".."))
		return (-1);
	return (0);
}

int		init_save()
{
	if (!opendir(SAVE))
	{
		if (mkdir(SAVE, MODE_DIR))
			return (-1);
		if (errno == ENOENT)
			return (is_datafile());
		else
			return (-1);
	}
	return (is_datafile());
}
