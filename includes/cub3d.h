/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:34:15 by Sophie            #+#    #+#             */
/*   Updated: 2021/03/30 16:27:29 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

#define ERROR "Error/n"
#endif

typedef struct s_img
{

	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}				t_img;

typedef struct  s_data 
{
	void	*mlx_ptr;
    void	*win_ptr;
	int		i;
	int		c;
	int		f;
	t_img	img;
	t_win	win;
}               t_data;


typedef struct s_rect
{
	int x;
	int y;
	int height;
	int width;
	int color;
}				t_rect;

typedef struct s_win
{
	int width;
	int height;
}				t_win;

enum e_errors
{
	MISSING_INFOS = 1,
	MAP_IS_MISSING,
	ERROR_FORMAT,
	MAP_IS_OPEN,
	VALUE_ERROR,
	OPENING_ERROR	
}

int 	main(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int		handle_keypress(int keysym, t_data *data);
int		display(t_data *data);
void	render_background(t_img *img, int color);
void    ft_init_data(t_data *data);
void	ft_color(char *str, t_data *data);
int		ft_check_map(char *str, t_data *data);

	#endif