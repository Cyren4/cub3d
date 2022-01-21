# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 13:33:21 by cramdani          #+#    #+#              #
#    Updated: 2022/01/09 18:25:42 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include cub3D.mk

SRCS_DIR	=	srcs
OBJS_DIR	=	objs
INC_DIR		=	includes

SRCS	:=	$(addprefix $(SRCS_DIR)/, $(FILES))
OBJS 	:=	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))
INCLUDE	:=	$(addprefix $(INC_DIR)/, $(HEADER))

NAME 	=	cub3D

INC		=	-include $(INCLUDE)
CC		=	gcc
CFLAGS	= 	-Wall -Wextra -Werror 
RM		=	rm -rf

OS := $(shell uname -s)
ifeq ($(OS),Darwin) ## mac 
	CFLAGS += -D MACOS -fsanitize=address
	MLX_P	= mlx
	LFLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit -lz
endif
ifeq ($(OS),Linux) ##linux
	MLX_P	= minilibx-linux
	LFLAGS	= -lXext -lX11 -lm
endif

LIBFT_P	= libft

LIB			= $(LIBFT_P)/libft.a $(MLX_P)/libmlx.a

# OBJS	=	${SRCS:.c=.o}

all		:	${NAME}
bonus	: ${NAME_BONUS}	

$(NAME) : $(OBJS) 
		make -C $(LIBFT_P)
		make -C $(MLX_P)
		$(CC) -o $@ $^ $(LIB) $(LFLAGS) $(CFLAGS)

# %.o		:	%.c %.h
# 			@$(CC) -w $(CFLAGS)  -c  $< $(LIB) 
			
$(OBJS_DIR):
		@mkdir -p $@
		@mkdir $(addprefix $(OBJS_DIR)/, $(SUB_DIR))
		@printf "Create object directories : $(GREEN)$(OBJS_DIR)\n$(END)"
		@printf "Create object subdirectories : $(GREEN)$(SUB_DIR)\n$(END)"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | ${OBJS_DIR}
	    	@$(CC) $(CFLAGS) -c $< -o $@ 

clean	:
		$(RM) $(OBJS_DIR) 
		make fclean -C $(LIBFT_P)
		make clean -C $(MLX_P) 
		@printf "$(RED)Cleaning is done!\n$(END)"

fclean	:	clean
			$(RM) $(NAME)
			@printf "$(YELLOW)FCleaning is done!\n$(END)"

re		:	fclean all

.PHONY	:	all clean fclean re
