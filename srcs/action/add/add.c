#include "../../../includes/ulysse.h"

static	char	*get_string_file(char *path)
{
	int	fd;
	char	buffer[BUFFER_SIZE];
	char	*tmp;
	char	*string;

	tmp = NULL;
	if (!(string = ft_calloc(1, 1)))
		return (NULL);
	if ((fd = open(path, O_RDONLY)) < 0)
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

static	int	add_new_file(char *av)
{
	int	fd;
	char	*string;
	char	**txt;
	char	*filename;

	string = NULL;
	txt = NULL;
	fd = 0;
	if (!(filename = get_file_name(av)))
		return (-1);
	if (!(string = get_string_file(av)))
	{
		free(filename);
		return (-1);
	}
	if (chdir(SAVE))
	{
		free(filename);
		free(string);
		return (-1);
	}
	if (!(txt = get_file(DATAFILE)))
	{
		free(filename);
		free(string);
		return (-1);
	}
	if (chdir(txt[0]))
	{
		free(filename);
		free(string);
		free_get_file(txt);
		return (-1);
	}
	free_get_file(txt);
	if (chdir(FILES))
	{
		free(string);
		free(filename);
		return (-1);
	}
	if ((fd = open(filename, O_CREAT, MODE_FILE)) < 0)
	{
		free(filename);
		free(string);
		return (-1);
	}
	if (close(fd))
	{
		free(filename);
		free(string);
		return (-1);
	}
	if ((fd = open(filename, O_WRONLY)) < 0)
	{
		free(filename);
		free(string);
		return (-1);
	}
	ft_putstr_fd(string, fd);
	free(filename);
	free(string);
	if (close(fd))
		return (-1);
	if (chdir(EXEPATH))
		return (-1);
	return (0);
}

static	int	match_rule(char *txt, char *rule)
{
	int	i;

	i = 0;
	while (txt && rule && txt[i] && txt[i] != ' ' && rule[i])
	{
		if (txt[i] != rule[i])
			return (0);
		++i;
	}
	if (txt[i] != '\0' && txt[i] != ' ')
		return (0);
	if (rule[i] != '\0')
		return (0);
	return (1);
}

static	int	does_rule_exist_add(char *rule)
{
	int	i;
	char	**txt;

	i = 0;
	txt = NULL;
	if (!(txt = get_file(DATAFILE)))
		return (-1);
	while (txt[i])
	{
		if (match_rule(txt[i], rule))
			return (-1);
		++i;
	}
	return (0);
}

int		add(t_env *env)
{
	char	**txt;
	char	*file_name;
	char	*rule_name;

	txt = NULL;
	rule_name = NULL;
	file_name = NULL;
	if (env->av.argc < 3)
		return (error_add_av_missing(env));
	if (access(env->av.two, F_OK))
		return (error_add_wrong_av(env));
	if (chdir(EXEPATH))
		return (error_reinstall(env));
	if (chdir(SAVE))
		return (error_reinstall(env));
	if (!(txt = get_file(DATAFILE)))
		return (error_reinstall(env));
	if (chdir(txt[0]))
		return (error_reinstall(env));
	free_get_file(txt);
	if (!(file_name = get_file_name(env->av.two)))
		return (error_reinstall(env));
	if (!(rule_name = get_rule_name(file_name)))
		return (error_reinstall(env));
	if (does_rule_exist_add(rule_name))
		return (error_add_rule_exist(env, rule_name, file_name));
	if (insert_rule(file_name, rule_name))
		return (error_reinstall(env));
	free(file_name);
	free(rule_name);
	if (chdir(EXEPATH))
		return (error_reinstall(env));
	if (add_new_file(env->av.two))
		return (-1);
	return (0);
}
