
FILES	+=  	\
			parsing/get_file.c           	\
			parsing/parser.c             	\
			parsing/main.c               	\
			parsing/map.c                	\
			parsing/color.c              	\
			parsing/get_next_line.c      	\
			parsing/utils.c              	\
			parsing/free.c               	\
			parsing/init.c               	\


SUB_DIR = parsing raycasting

HEADER		= cub3d.h move.h

BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
END		=	\033[m