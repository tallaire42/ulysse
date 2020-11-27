#include "../../../includes/ulysse.h"

/*
** nake the first part of the file's path according to the branch's path
*/

static	char	*make_path_start(char *branch)
{
	char	*path;
	size_t	size;
	size_t	i;

	size = ft_strlen(branch);
	i = 0;
	while (size > 0 && branch[size] != '/')
		--size;
	if (!(path = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	while (i <= size)
	{
		path[i] = branch[i];
		++i;
	}
	path[i] = '\0';
	return (path);
}

/*
** make and add the end of the path file to the start of the path file
*/

static	char	*add_path_end(char *start, char *dir, char *name)
{
	char	*path;
	size_t	size;

	size = ft_strlen(start) + ft_strlen(dir) + ft_strlen(name) + 2;
	if (!(path = malloc(sizeof(char) * size)))
		return (NULL);
	ft_strcpy(path, start);
	ft_strcat(path, dir);
	ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}

/*
** find the rule from the file name
*/

static	char	*get_rule(char *str)
{
	char	*rule;
	size_t	size;
	size_t	i;

	rule = NULL;
	size = ft_strlen(str);
	i = 0;
	if (c_is_str(str, '.') < 0)
		return (rule = ft_strdup(str));
	while (size > 0 && str[size] != '.')
		--size;
	if (!(rule = ft_calloc(size + 1, sizeof(char))))
	{
		printf("Error\nAlloc memory failed with %s file", str);
		return (NULL);
	}
	while (i < size)
	{
		rule[i] = str[i];
		++i;
	}
	rule[i] = '\0';
	return (rule);
}

/*
** make the path of the file
*/

char		*get_added_path(t_env *env)
{
	char	*path_file;
	char	*file_name;

	path_file = NULL;
	env->add.rule = NULL;
	if (!(file_name = get_file_name(env->av.three)))
		return (NULL);
	if (!(env->add.rule = get_rule(file_name)))
		return (NULL);
	if (!(path_file = make_path_start(env->branch.path)))
	{
		printf("Error\nFailed alloc memory path of %s\n", file_name);
		return (NULL);
	}
	if (!(path_file = add_path_end(path_file, "files", file_name)))
	{
		printf("Error\nFailed alloc memory path of %s\n", file_name);
		return (NULL);
	}
	return (path_file);
}
