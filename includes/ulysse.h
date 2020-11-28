#ifndef DEF_ELEC_H
# define DEF_ELEC_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include "lib_h/libft.h"
# include "struct.h"

/*
** #####################################
** ############### MACRO ###############
** #####################################
*/

/*
** ############## ACTIONS ##############
*/

# define PRINT          1
# define PRINT_ACT      "print"
# define HELP           2
# define HELP_ACT       "help"
# define ADD            3
# define ADD_ACT        "add"
# define SET            4
# define SET_ACT        "set"

/*
** ########### FILES AND DIRS ##########
*/

# define SAVE           "save"
# define DATAFILE       "data.uly"
# define TMPDIR         "tmp"
# define MODE_DIR       00771
# define MODE_FILE      00666

/*
** ############## COLORS ###############
*/

//#include <iostream>

#ifndef BG_LIGHT

#define BLACK           "\033[1;30m"
#define RED             "\033[1;31m"
#define GREEN           "\033[1;32m"
#define YELLOW          "\033[1;33m"
#define BLUE            "\033[1;34m"
#define PURPLE          "\033[1;35m"
#define CYAN            "\033[1;36m"
#define GREY            "\033[1;37m"
#define NC              "\033[0m"

#else

#define BLACK           "\033[0;30m"
#define RED             "\033[0;31m"
#define GREEN           "\033[0;32m"
#define YELLOW          "\033[0;33m"
#define BLUE            "\033[0;34m"
#define PURPLE          "\033[0;35m"
#define CYAN            "\033[0;36m"
#define GREY            "\033[0;37m"
#define NC              "\033[0m"

#endif

/*
** #####################################
** ############# FUNCTIONS #############
** #####################################
*/

/*
** add
*/

int	add(t_env *env);
int	cpy_file(t_env *env);
char	*get_file_name(char *path);
int	check_rule(char *av);
char	*get_added_path(t_env *env);
int	insert_rule(t_env *env);

/*
** checker
*/

int	check_data(char **txt);

/*
** free
*/

void	*free_ulysse(t_env *env, int end);

/*
** help
*/

void		help(t_env *env);

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
char	*wich_branch(char *file_path);

/*
** print
*/

int	print(t_env *env);
int	print_file(char *path_file);

/*
** set
*/

int	set(t_env *env);

/*
** utils
*/

int	at_error(char *str);
int	at_open(char *file_name);
char	*at_err_null(char *str);
char	**get_file(char *file_name);
char	*strdup_sep(char *str, char sep);

# endif
