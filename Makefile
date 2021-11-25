NAME = fract-ol

SRC = 	fractol.c \
		draw.c \
		zoom.c \
		ft_argv_check.c \
		get_colour.c
INCLUDE = -I ./includes
OBJ = $(SRC:%.c=%.o)

LIBFT_DIR = ./libft
MLX_DIR = ./mlx

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.dylib

# COLORS
PINK    = \x1b[35m
BLUE    = \x1b[34m
YELLOW  = \x1b[33m
GREEN   = \x1b[32m
RED     = \x1b[31m
MAGENTA = \x1b[35m

RESET   = \x1b[0m

FLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

WIN = -D WIN_SIZE=400


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	gcc $(OBJ) $(WIN) -L. $(MLXFLAGS) $(FLAGS)  $(LIBFT) -o $(NAME) 

%.o: %.c
	gcc -c $(INCLUDE) $(FLAGS) $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)
$(MLX):
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX) .

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJ) libmlx.dylib

fclean: clean
	rm -f $(NAME)

re:	fclean all
