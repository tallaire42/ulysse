#ifndef DEF_ELEC_H
# define DEF_ELEC_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "lib_h/libft.h"
# include "struct.h"

/*
** ############### MACRO ###############
*/

# define PRINT 1
# define PRINT_ACT "print"

/*
** checker
*/

int	check_data(t_env *env);

/*
** free
*/

void	*free_ulysse(t_env *env, int end);

/*
** init
*/

void	init(t_env *env);
void	init_file(t_env *env);

/*
** main
*/

int	start_ulysse(t_env *env);

/*
** parser
*/

void	*get_data(t_env *env);
int	get_index(t_env *env);
int	parser(t_env *env);
int	wich_action(char *av);

/*
** print
*/

int	print(t_env *env);
int	print_file(char *path_file);

/*
** utils
*/

int	at_error(char *str);
int	at_open(char *file_name);
char	*at_err_null(char *str);
char	**get_file(char *file_name);
char	*strdup_sep(char *str, char sep);

# endif
