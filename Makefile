NAME	=	elec

CC	=	clang

RM	=	rm -rf

CP	=	cp -r

CFLAGS	=	-Werror -Wextra -Wall -c

SRC		+=	at_error.c
SRC		+=	at_open.c
SRC		+=	check_data.c
SRC		+=	elec.c
SRC		+=	free.c
SRC		+=	get_data.c
SRC		+=	get_file.c
SRC		+=	init.c
SRC		+=	init_file.c
SRC		+=	main.c
SRC		+=	parser.c

OBJ_PATH	=	./.obj/

vpath %.c srcs/
vpath %.c srcs/checker
vpath %.c srcs/free
vpath %.c srcs/init
vpath %.c srcs/main
vpath %.c srcs/parser
vpath %.c srcs/utils

OBJ		=	$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))

LIBFT_NAME	=	libft.a

LIB_PATH	=	./.lib

LIBFT_PATH	=	./libft

LIBFT_SRC	=	$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

LIBFT		=	$(addprefix $(LIB_PATH)/, $(LIBFT_NAME))

all: $(NAME)

$(NAME): $(LIB_PATH) $(LIBFT) $(OBJ_PATH) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): $(OBJ_PATH)%.o: %.c
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

