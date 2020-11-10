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

char	**free_get_file(char **txt, size_t *size);
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
char	**get_file(t_env *env, char *file_name, size_t *size_file);
int	parser(t_env *env);

/*
** utils
*/

int	at_error(char *str);
int	at_open(char *file_name);
char	*at_err_null(char *str);

# endif
