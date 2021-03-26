/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:34:15 by Sophie            #+#    #+#             */
/*   Updated: 2021/03/26 11:27:48 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"

typedef struct  s_data 
{	
	void	*image;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	void	*mlx_ptr;
    	void	*mlx_win;
    	void	*mlx;
    	void	*win;
	int	bullshit;
}               t_data;

int main(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	key_hook(int keycode, t_data *data);
int	display(t_data *data);

#endif

