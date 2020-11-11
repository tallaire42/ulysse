#ifndef DEF_STRUCT_H
# define DEF_STRUCT_H

typedef		struct	s_data
{
	char	**rules;
	char	**path;
	char	***def;
	size_t	size;
	char	**txt;
}			t_data;

typedef		struct	s_av
{
	char	*one;
	char	*two;
}			t_av;

typedef		struct	s_print
{
	int	index;
	int	fd;
}			t_print;

typedef		struct	s_env
{
	t_print	print;
	t_av	av;
	t_data	data;
}			t_env;

# endif
