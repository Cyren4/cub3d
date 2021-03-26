NAME = test

SOURCEDIR = ./srcs/

INCLUDES = ./includes/

SRCS = $(MAIN)main.c my_mlx_pixel_put.c\

OBJS := ${SRCS:c=o}

CC = gcc -g $(FLAGS)

FLAGS = -I. -I$(INCLUDES) -Wall -Werror -Wextra -fsanitize=address
LIBS = ./libft

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	make -C $(LIBS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L$(LIBS) -lft  -o $(NAME)

clean:
	rm $(OBJS)
	make clean -C ./libft

fclean: clean
	rm $(NAME)

re : fclean all
