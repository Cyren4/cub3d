/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:34:15 by Sophie            #+#    #+#             */
/*   Updated: 2021/05/12 15:44:45 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
//#include <X11/X.h>
//#include <X11/keysym.h>
//#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

#define ERROR "Error/n"

typedef struct s_img
{

	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}				t_img;
typedef struct s_win
{

	int width;
	int height;
	int	ceiling_color;
	int	floor_color;
}				t_win;

typedef struct  s_data 
{
	void	*mlx_ptr;
    void	*win_ptr;
	int		i;
	int		c;
	int		f;
	int	set_infos;
	char	player;
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



enum e_errors
{
	MISSING_INFOS = 2,
	OPENING_ERROR,
	NO_CONFIG_FILE,
	WRONG_EXTENSION,
	MAP_IS_MISSING,
	ERROR_FORMAT,
	MAP_IS_OPEN,
	VALUE_ERROR,
	MISSING_PLAYER,
	WRONG_CHARACTER
	
};

int 	main(int ac, char **av);
/*render*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int		handle_keypress(int keysym, t_data *data);
int		display(t_data *data);
void	render_background(t_img *img, int color);
/*parsing*/

int 	ft_parser(int fd, t_data *data)
void    ft_init_data(t_data *data);
void	ft_set_color(char *line, int i, t_data *data);
void 	ft_set_resolution(char *line, int i, t_data *data);
int		ft_check_map(char *line);
int 	parse_infos(char *line, int i, t_data *data);
int		check_color_value(int c);
int		ft_check_extension(char *str, char *ext);
int		get_next_line(int fd, char **line);

#endif
