#ifndef DEF_STRUCT_H
# define DEF_STRUCT_H

typedef		struct	s_add
{
	char	*rule;
}			t_add;

typedef		struct	s_branch
{
	char	*path;
}			t_branch;

typedef		struct	s_data
{
	char	**rules;
	char	**path;
	size_t	size;
	char	**txt;
}			t_data;

typedef		struct	s_av
{
	char	*one;
	char	*two;
	char	*three;
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
