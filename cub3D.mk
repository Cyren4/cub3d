
FILES	=	main.c \
			check_map.c \
			error.c \
			map_utils.c \
			game_utils.c \
			moveP.c \
			render.c \
			start.c

SUB_DIR = parsing cub_utils execution

HEADER		= so_long.h move.h texture.h

BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
END		=	\033[m