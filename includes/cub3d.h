/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:34:15 by Sophie            #+#    #+#             */
/*   Updated: 2022/01/21 10:54:33 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// #include <X11/X.h>
// #include <X11/keysym.h>
#include <string.h>
#include "/root/42/cub3D/libft/libft.h"
#include <errno.h>
# define DIRECTIONS "NSEW"
# define VALID_CHARACTERS "01234NSEW"

/*KEYS*/
# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

enum PATH
{
	NO,
	SO,
	EA,
	WE
};
 
typedef struct s_img
{

	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_text
{
	char *path_no;
	char *path_so;
	char *path_ea;
	char *path_we;
}
				t_text;
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
	t_text	txt;
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
int		open_file(int *fd, int ac, char **argv);
void	print_map(char **infos);
void 	init(t_data *d);
int		get_next_line(int fd, char **line);
void	get_file(t_data *d, int fd, int lvl);
int 	ft_parser(char *fichier,int fd);
int		ft_set_color(char **infos, int i, t_data *data);
int		ft_check_map(char *line);
void 	parse_infos(t_data *data);
int		check_value(int c);
int 	get_rgb(int rgb, int r, int g, int b);
int 	ft_set_color(char **infos, int i, t_data *data);
int		ft_check_extension(char *str, char *ext);

/*utils*/
int		is_whitespace(char c);
int		is_in_array(char **array, char *str);
int		free_map(t_data *d);
char	**build_array(void);

#endif
