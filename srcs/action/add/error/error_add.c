#include "../../../../includes/ulysse.h"

int		error_add_av_missing(t_env *env)
{
	free_main_av(env);
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("The argument %sfile's path%s is missing\n", GREEN, NC);
	ft_printf("To use %sadd%s action, ", GREEN, NC);
	ft_printf("please write your command as follow :\n\n");
	ft_printf("uly unset %sPATH%s\n", GREEN, NC);
	return (-1);
}

int		error_add_wrong_av(t_env *env)
{
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("Can't find or open %s%s%s\n", PURPLE, env->av.two, NC);
	free_main_av(env);
	return (-1);
}

int		error_add_rule_exist(t_env *env, char *rule_name, char *file_name)
{
	ft_printf("%sError%s\n\n", RED, NC);
	ft_printf("%s%s%s rule already exists\n", PURPLE, rule_name, NC);
	free_main_av(env);
	free(rule_name);
	free(file_name);
	return (-1);
}
