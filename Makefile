NAME = fract-ol

SRC = 	main.c

OBJ = $(SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -L. -fsanitize=address -lmlx -framework OpenGL -framework AppKit -o $(NAME) -D WIN_SIZE=200
	./$(NAME)

%.o: %.c
	gcc -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
