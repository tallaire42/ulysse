#ifndef DEF_STRUCT_H
# define DEF_STRUCT_H

typedef		struct	s_data
{
	char	**rules;
	char	***def;
	size_t	size;
	char	**txt;
}			t_data;

typedef		struct	s_av
{
	char	*one;
}			t_av;

typedef		struct	s_file
{
	size_t	size;
}			t_file;

typedef		struct	s_env
{
	t_file	file;
	t_av	av;
	t_data	data;
}			t_env;

# endif
