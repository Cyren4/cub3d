NAME = test

SOURCEDIR = ./srcs/

INCLUDES = ./includes/

SRCS = $(MAIN)main.c my_mlx_pixel_put.c\

OBJS := ${SRCS:c=o}

CC = clang -g $(FLAGS)

FLAGS = -I. -I$(INCLUDES) -Wall -Werror -Wextra -fsanitize=address
LIBS = ./libft

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	make -C $(LIBS)
	make -C mlx_linux
	$(CC) $(OBJS) -L$(LIBS) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME)
clean:
	rm $(OBJS)
	make clean -C ./libft

fclean: clean
	rm $(NAME)

re : fclean all
