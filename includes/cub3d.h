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

typedef struct  s_data 
{	
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
    void	*mlx_win;
	void	*mlx;
	void	*win;
	int		bullshit;
}               t_data;

int 	main(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_keypress(int keysym, t_data *data);
int		display(t_data *data);
void	render_background(t_data *data, int color);

#endif
