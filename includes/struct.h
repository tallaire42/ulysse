#ifndef DEF_STRUCT_H
# define DEF_STRUCT_H

typedef		struct	s_file
{
	char	*name;
	int	fd;
}			t_file;

typedef		struct	s_env
{
	t_file	file;
}			t_env;

# endif
