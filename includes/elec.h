#ifndef DEF_ELEC_H
# define DEF_ELEC_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "lib_h/libft.h"
# include "struct.h"

/*
** checker
*/

int	check_data(t_env *env);

/*
** free
*/

void	*free_elec(t_env *env, int end);

/*
** init
*/

void	init(t_env *env);
void	init_file(t_env *env);

/*
** main
*/

int	start_elec(t_env *env);

/*
** parser
*/

void	*get_data(t_env *env);
char	**get_file(t_env *env, char *file_name);
int	get_index(t_env *env);
int	parser(t_env *env);

/*
** utils
*/

int	at_error(char *str);
int	at_open(char *file_name);
char	*at_err_null(char *str);
char	*strdup_sep(char *str, char sep);

# endif
