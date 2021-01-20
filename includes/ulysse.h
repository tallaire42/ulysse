#ifndef DEF_ULYSSE_H
# define DEF_ULYSSE_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include "lib_h/libft.h"
# include "lib_h/ft_printf.h"
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
# define UNSET          5
# define UNSET_ACT      "unset"
# define LS             6
# define LS_ACT         "ls"
# define BRANCH         7
# define BRANCH_ACT     "branch"
# define CD             8
# define CD_ACT         "cd"
# define RM             9
# define RM_ACT         "rm"

/*
** ########### FILES AND DIRS ##########
*/

# define EXEPATH        "/home/harlock/projet/ulysse"
# define SAVE           "save"
# define DATAFILE       "data.uly"
# define TMPDIR         "tmp"
# define FILES          "files"
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
char	*get_file_name(char *av);
char	*get_rule_name(char *av);
int	insert_rule(char *av, char *rule);
int	write_rule(char *string, char *av, char *rule);

/*
** cd
*/

int	cd(t_env *env);
char	**switch_branch(char **txt, char *av);

/*
** checker
*/

int	check_data(char **txt);

/*
** error
*/

int	error_reinstall(t_env *env);
int	error_wrong_branch(t_env *env, char **txt, char *branch);

/*
** error add
*/

int	error_add_av_missing(t_env *env);
int	error_add_rule_exist(t_env *env, char *rule_name, char *file_name);
int	error_add_wrong_av(t_env *env);

/*
** error cd
*/

int	error_cd_reinstall(t_env *env);
int	error_cd_av_missing(t_env *env);
int	error_cd_wrong_av(t_env *env, char **txt);

/*
** error ls
*/

int	error_ls_wrong_av(t_env *env);

/*
** error_print
*/

int	error_print_av_missing(t_env *env);
int	error_print_rule_doesnt_exist(t_env *env);

/*
** error set
*/

int	error_set_av_missing(t_env *env);
int	error_set_branch_exist(t_env *env);
int	error_set_write_branch(t_env *env);
int	error_set_init_branch(t_env *env);
int	error_set_init_save(t_env *env);

int	error_ulysse_action(t_env *env);

/*
** error unset
*/

int	error_unset_av_missing(t_env *env);

/*
** help
*/

void	help(t_env *env);

/*
** ls
*/

int	ls(t_env *env);
int	print_branch(t_env *env);

/*
** main
*/

void	free_main_av(t_env *env);
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
int	print_file(char *av, char **txt);

/*
** rm
*/

int	error_rm_wrong_rule(t_env *env);
int	error_rm_av_missing(t_env *env);
int	rm(t_env *env);

/*
** set
*/

int	init_save(t_env *env);
int	init_branch(t_env *env);
int	set(t_env *env);
int	write_branch(t_env *env);

/*
** unset
*/

int	unset(t_env *env);
int	close_branch_fs(t_env *env);
int	rm_branch_datafile(t_env *env);

/*
** utils
*/

int	does_rule_exist(char *rule, char **txt);

# endif
