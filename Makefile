NAME = fract-ol

SRC = 	main.c \
		draw.c \
		zoom.c \
		ft_argv_check.c \
		get_colour.c
INCLUDE = -I ./includes
OBJ = $(SRC:%.c=%.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

# COLORS
PINK    = \x1b[35m
BLUE    = \x1b[34m
YELLOW  = \x1b[33m
GREEN   = \x1b[32m
RED     = \x1b[31m
MAGENTA = \x1b[35m

RESET   = \x1b[0m

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

WIN = -D WIN_SIZE=400


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(OBJ) $(WIN) -L. $(MLXFLAGS) $(FLAGS)  $(LIBFT) -o $(NAME) 

%.o: %.c
	gcc -c $(INCLUDE) $(FLAGS) $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
