/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:34:15 by Sophie            #+#    #+#             */
/*   Updated: 2022/01/19 18:09:58 by ldes-cou         ###   ########.fr       */
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
#include <string.h>
#include "../libft/libft.h"
#include <errno.h>

/*KEYS*/
# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

typedef struct s_img
{

	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;


typedef struct s_win
{

	int width;
	int height;

}				t_win;

typedef struct  s_data 
{
	void	*mlx_ptr;
    void	*win_ptr;
	int		i;
	int		c;
	int		f;
	int		infos;
	char	player;
	char	**file;
	int		ceiling;
	int		floor;
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




int 	main(int ac, char **av);
/*render*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int		handle_keypress(int keysym, t_data *data);
int		display(t_data *data);
void	render_background(t_img *img, int color);

/*parsing*/
void	print_map(char **infos);
void 	init(t_data *d);
int		free_map(t_data *d);
int		check_file(int fd, int ac, char **argv);
int 	ft_parser(char *fichier,int fd);
void    ft_init_data(t_data *data);
int		ft_set_color(char **infos, int i, t_data *data);
void 	ft_set_resolution(char **infos, int i, t_data *data);
int		ft_check_map(char *line);
int 	parse_infos(char **infos, t_data *data);
int		check_value(int c);
int 	get_rgb(int rgb, int r, int g, int b);
int 	ft_set_color(char **infos, int i, t_data *data);
int		ft_check_extension(char *str, char *ext);
int		get_next_line(int fd, char **line);
void	get_file(t_data *d, int fd, int lvl);

/*utils*/
int		is_whitespace(char c);


#endif
