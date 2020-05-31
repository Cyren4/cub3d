#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../minilibx/mlx.h"

typedef struct s_data
{
    int     win_size_x;
    int     win_size_y;
    void    *mlx_ptr;
	void    *mlx_win;
}               t_data;


typedef struct  s_conf
{
    int     resol[3];
    char    *text[5];//0 = SO, 1 = WE, 2 = EA, 3 = NO, 4 = split
    int     col[2][3]; // 0 = F , 1 = C
}               t_conf;

typedef struct s_map
{
    char    **map;
    int     *len;
    int     height;
}               t_map;

int         check_name_file(int ac, char **av);

int         check_cub(char *cub, t_conf *conf, t_map *map);
int         check_conf(int fd, char **line, t_conf *conf, t_map *map);
int         check_map(int fd, char **line, t_map *map);
int         check_line(char *line, t_conf *conf, int *all_c);
int         text(char **sep, t_conf *conf, int *all_c, int i);
int         res(char **sep, t_conf *conf, int *all_c, int i);
int         color(char *line, t_conf *conf, int *all_c, int i);

int         error_message(int *check);
int         clear(char **sep, int ret);
int         all_good(int *check);
int         len(char **str);
//int         all_valid(t_conf *conf, int *check);
#endif