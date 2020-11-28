#include "../../../includes/ulysse.h"

static	int	av_missing(void)
{
	printf("Error\n");
	printf("The name of the NEW_BRANCH is missing\n");
	printf("Please specify the name of the new branch to create\n");
	printf("As follow :\n\n");
	printf("uly set NEW_BRANCH\n\n");
	return (-1);
}

int		set(t_env *env)
{
	if (env->av.argc == 2)
		return av_missing();
	return (0);
}
