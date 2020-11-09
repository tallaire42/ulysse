#ifndef DEF_STRUCT_H
# define DEF_STRUCT_H

typedef		struct	s_av
{
	char	*one;
}			t_av;

typedef		struct	s_file
{
	int	fd;
	int	size;
	char	**txt;
}			t_file;

typedef		struct	s_env
{
	t_file	file;
	t_av	av;
}			t_env;

# endif
