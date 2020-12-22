#ifndef DEF_STRUCT_H
# define DEF_STRUCT_H

typedef		struct	s_add
{
	char	*rule;
}			t_add;

typedef		struct	s_data
{
	char	*curpath;
	int	fd;
}			t_data;

typedef		struct	s_branch
{
	char	**rules;
	char	**path;
	char	**txt;
}			t_branch;

typedef		struct	s_av
{
	char	*one;
	char	*two;
	char	*three;
	int	argc;
	int	act;
}			t_av;

typedef		struct	s_env
{
	t_av		av;
	t_data		data;
	t_branch	branch;
	t_add		add;
}			t_env;

# endif
