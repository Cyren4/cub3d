/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:34:15 by Sophie            #+#    #+#             */
/*   Updated: 2022/01/24 17:10:57 by ldes-cou         ###   ########.fr       */
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
#include "../libft/libft.h"
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
int		get_next_line(int fd, char **line);

/*get_file*/
int		open_file(int *fd, int ac, char **argv);
void	get_file(t_data *d, int fd, int lvl);

/*parser*/
void 	parse_infos(t_data *data);
int		check_infos(t_data *d);

/*color*/
int		get_color(char *line);

/*map*/
void	check_map(t_data *d, int i);
void	check_char(t_data *d, char *line);
void    find_player(t_data *d);
void	print_map(char **infos);
void 	init(t_data *d);


/*utils*/
int		is_cardinal(char *line);
int		is_whitespace(char c);
int		is_in_array(char **array, char *str);
char	**split_trim(char *line);

/*free*/
void	free_array(char **array);
void	free_exit(t_data *d);

#endif
