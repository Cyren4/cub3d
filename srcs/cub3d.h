#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
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
    int resol[2];
    char *SO;
    char *WE;
    char *EA;
    char *NO;
    char *split;
    int F[3];
    int C[3];
}               t_conf;

typedef struct s_map
{
    char    **map;
    int     *len;
    int     height
}               t_map;

int     check_name_file(int ac, char **av);
int     check_cub(char *cub, t_conf *conf, t_map *map);
void	check_win(int max_x, int max_y, t_data *data);

#endif