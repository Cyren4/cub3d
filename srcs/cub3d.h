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

#endif