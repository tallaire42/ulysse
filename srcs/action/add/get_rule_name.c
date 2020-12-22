#include "../../../includes/ulysse.h"

static	char	*remove_extension(char *name)
{
	size_t	i;
	size_t	size;
	char	*new;

	size = ft_strlen(name);
	i = 0;
	while (size > 0 && name[size] != '.')
		--size;
	if (size == 0)
		return (name);
	size -= i;
	if (!(new = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = name[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}

char		*get_rule_name(char *av)
{
	char	*name;

	name = NULL;
	if (!(name = remove_extension(av)))
		return (NULL);
	return (name);
}
