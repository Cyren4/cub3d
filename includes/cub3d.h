/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:34:15 by Sophie            #+#    #+#             */
/*   Updated: 2022/01/24 14:07:03 by ldes-cou         ###   ########.fr       */
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
#include "/mnt/nfs/homes/ldes-cou/42cursus/cub3d/libft/libft.h"
#include <errno.h>
# define DIRECTIONS "NSEW"
# define VALID_CHAR "01NSEW "

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
typedef struct s_play
{
	char	orientation;
	int		x;
	int		y;
}
				t_play;

typedef struct s_win
{

	void	*mlx_ptr;
    void	*win_ptr;
	int width;
	int height;

}				t_win;

typedef struct  s_data 
{
	bool	open_map;
	int		i;
	int		c;
	int		f;
	int		infos;
	char	**copy;
	char	**map;
	char	**file;
	int		ceiling;
	int		floor;
	t_play	play;	
	t_img	img;
	t_win	win;
	t_text	txt;
}               t_data;


int 	main(int ac, char **av);
/*render*/

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void	img_pix_put(t_img *img, int x, int y, int color);
// int		handle_keypress(int keysym, t_data *data);
// int		display(t_data *data);
// void	render_background(t_img *img, int color);

/*parsing*/
void    find_player(t_data *d);
void		flood_fill(t_data *d, int x, int y);
char	**copy_map(char **file);
int		is_cardinal(char *line);
void	check_map(t_data *d, int i);
void		check_char(t_data *d, char *line);
int		check_infos(t_data *d);
int		open_file(int *fd, int ac, char **argv);
void	print_map(char **infos);
void 	init(t_data *d);
int		get_next_line(int fd, char **line);
void	get_file(t_data *d, int fd, int lvl);
int		get_color(char *line);
int 	ft_parser(char *fichier,int fd);
void	get_map(t_data *d, int i);
int		ft_check_map(char *line);
void 	parse_infos(t_data *data);
int		check_value(char **rgb);
int 	get_rgb(int rgb, int r, int g, int b);


/*utils*/
int		is_whitespace(char c);
int		is_in_array(char **array, char *str);
void	free_array(char **array);
char	**build_array(void);
char	**split_trim(char *line);

/*free*/

void free_exit(t_data *d);

#endif
