#ifndef DEF_ELEC_H
# define DEF_ELEC_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "lib_h/libft.h"
# include "struct.h"

/*
** free
*/

void	free_elec(t_env *env);

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

int	get_file(t_env *env);
int	parser(t_env *env);

/*
** utils
*/

int	at_error(char *str);

# endif
