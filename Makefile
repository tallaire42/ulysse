NAME	=	ulysse

CC	=	clang

RM	=	rm -rf

CP	=	cp -r

CFLAGS	=	-Werror -Wextra -Wall -c

SRC		+=	close_branch_fs.c
SRC		+=	error_ulysse.c
SRC		+=	error_set.c
SRC		+=	error_set_write_branch.c
SRC		+=	error_unset.c
SRC		+=	init_branch.c
SRC		+=	init_save.c
SRC		+=	main.c
SRC		+=	rm_branch_datafile.c
SRC		+=	set.c
SRC		+=	ulysse.c
SRC		+=	unset.c
SRC		+=	wich_action.c
SRC		+=	write_branch.c

#######################
####### ACTION ########
#######################

######### ADD #########

SRC		+=	add.c
SRC		+=	error_add.c
SRC		+=	get_file_name.c
SRC		+=	get_rule_name.c
SRC		+=	insert_rule.c
SRC		+=	write_rule.c

######### CD ##########

SRC		+=	cd.c
SRC		+=	error_cd.c
SRC		+=	switch_branch.c

######### LS ##########

SRC		+=	ls.c
SRC		+=	print_branch.c
SRC		+=	error_ls.c

####### PRINT #########

SRC		+=	print.c
SRC		+=	print_file.c
SRC		+=	error_print.c

######### RM ##########

SRC		+=	error_rm.c
SRC		+=	rm.c

#######################
######## ERROR ########
#######################

SRC		+=	error_reinstall.c
SRC		+=	error_wrong_branch.c

#######################
######## UTILS ########
#######################

SRC		+=	does_rule_exist.c

OBJ_PATH	=	./.obj/

vpath %.c srcs/
vpath %.c srcs/action
vpath %.c srcs/action/add
vpath %.c srcs/action/add/error
vpath %.c srcs/action/cd
vpath %.c srcs/action/cd/error
vpath %.c srcs/action/ls
vpath %.c srcs/action/ls/error
vpath %.c srcs/action/print
vpath %.c srcs/action/print/error
vpath %.c srcs/action/rm
vpath %.c srcs/action/rm/error
vpath %.c srcs/action/set
vpath %.c srcs/action/set/error
vpath %.c srcs/action/unset
vpath %.c srcs/action/unset/error
vpath %.c srcs/error
vpath %.c srcs/main
vpath %.c srcs/main/error
vpath %.c srcs/parser
vpath %.c srcs/utils

OBJ		=	$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))

LIBFT_NAME	=	libft.a

HEADER_NAME	=	ulysse.h

LIB_PATH	=	./.lib

HEADER_PATH	=	./includes

LIBFT_PATH	=	./libft

LIBFT_SRC	=	$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

LIBFT		=	$(addprefix $(LIB_PATH)/, $(LIBFT_NAME))

HEADER		=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

all: $(NAME)

$(NAME): $(LIB_PATH) $(LIBFT) $(OBJ_PATH) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$<		[$(C_GREEN)OK$(C_END)]"

$(OBJ): $(OBJ_PATH)%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@(cd $(LIBFT_PATH) && $(MAKE))
	@$(CP) $(LIBFT_SRC) $(LIB_PATH)

$(LIB_PATH):
	@mkdir $(LIB_PATH)

clean:
	@$(RM) $(OBJ_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) clean)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIB_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) fclean)

re: fclean all

