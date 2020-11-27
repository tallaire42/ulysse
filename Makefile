NAME	=	ulysse

CC	=	clang

RM	=	rm -rf

CP	=	cp -r

CFLAGS	=	-Werror -Wextra -Wall -c

SRC		+=	add.c
SRC		+=	at_error.c
SRC		+=	at_open.c
SRC		+=	check_data.c
SRC		+=	check_rule.c
SRC		+=	cpy_file.c
SRC		+=	free.c
SRC		+=	get_added_path.c
SRC		+=	get_data.c
SRC		+=	get_file.c
SRC		+=	get_file_name.c
SRC		+=	get_index.c
SRC		+=	help.c
SRC		+=	init.c
SRC		+=	init_file.c
SRC		+=	insert_rule.c
SRC		+=	main.c
SRC		+=	parser.c
SRC		+=	print_file.c
SRC		+=	print.c
SRC		+=	strdup_sep.c
SRC		+=	ulysse.c
SRC		+=	wich_action.c
SRC		+=	wich_branch.c

OBJ_PATH	=	./.obj/

vpath %.c srcs/
vpath %.c srcs/action/
vpath %.c srcs/action/add
vpath %.c srcs/action/help
vpath %.c srcs/action/print
vpath %.c srcs/checker
vpath %.c srcs/free
vpath %.c srcs/init
vpath %.c srcs/main
vpath %.c srcs/parser
vpath %.c srcs/print
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

$(OBJ): $(OBJ_PATH)%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@(cd libft && $(MAKE))
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

