NAME = Cub3d

SOURCEDIR = ./srcs/

INCLUDES_MAC = ./includes/


SRCS = $(MAIN)main.c \


OBJS := ${SRCS:c=o}

CC = clang -g $(FLAGS)

LIBS = ./libft


FLAGS = -I. -I$(INCLUDES) -Wall -Werror -Wextra


all: $(NAME)


$(NAME): $(OBJS) $(INCLUDES)
	make -C $(LIBS)
	make -C mlx_linux
	$(CC) $(OBJS) -L$(LIBS) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean:
	rm $(OBJS)
	make clean -C ./libft

fclean: clean
	rm $(NAME)

re : fclean all
