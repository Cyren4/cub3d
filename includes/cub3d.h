#ifndef CUB3D_H
#define CUB3D_H

/*	lib standard	*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// #include <X11/X.h>
// #include <X11/keysym.h>
#include <string.h>
#include <errno.h>

/*	mlx	*/
#ifdef MACOS
#include "../minilibx-linux/mlx.h"
#else
#include "../mlx/mlx.h"
#endif

/*	libft	*/
#include "../libft/libft.h"

/*	KEYS	*/
#include "move.h"
// #include "so_long.h"

/*	macro	*/
#define DIRECTIONS "NSEW"
#define VALID_CHAR "01NSEW "
#define SIZE_X 1000
#define SIZE_Y 700

enum PATH
{
	NO,
	SO,
	EA,
	WE
};

/*	struct	*/

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

typedef struct s_text
{
	char	*path_no;
	char	*path_so;
	char	*path_ea;
	char	*path_we;
} t_text;

typedef struct s_play
{
	char	orientation;
	int		x;
	int		y;
} t_play;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
} t_win;

typedef struct s_data
{
	int		n_line;
	bool	open_map;
	char	**map;
	char	**file;
	int		ceiling;
	int		floor;
	t_play	play;
	t_img	img;
	t_win	win;
	t_text	txt;
} t_data;

// ---------------- Parsing ----------------//

int		main(int ac, char **av);

/*get_file*/
int		open_file(int *fd, int ac, char **argv);
void	get_file(t_data *d, int fd, int lvl);

/*parser*/
void	parse_infos(t_data *data);
int		check_infos(t_data *d);

/*color*/
int		get_color(char *line);

/*map*/
void	check_map(t_data *d, int i);
void	check_char(t_data *d, char *line);
int 	find_player(t_data *d);
void	print_map(char **infos);
void	init(t_data *d);

/*utils*/

void	exit_error(char *error, t_data *d);
int		is_cardinal(char *line);
int		is_whitespace(char c);
int 	is_in_array(char **array, char *str);
char 	**split_trim(char *line);

/*free*/
void	free_array(char **array);
void	free_exit(t_data *d);

// ---------------- game ---------------- //

void start_game(t_data *data);

// ---------------- render ---------------- //

unsigned int	get_col(t_img *img, int x, int y);
int				render_frame(t_data *d);

int	close_g(t_data *d);

#endif
