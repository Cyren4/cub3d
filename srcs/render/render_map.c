/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:23:40 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/27 13:27:30 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//	get good size to display whole map
int	get_square(t_data *d){
	int	i;
	int	maxS;

	maxS = 0;
	i = 0;
	while (d->map[i])
	{
		if ((int)ft_strlen(d->map[i]) > maxS)
			maxS = ft_strlen(d->map[i]);
		i++;
	}
	if ((float)d->win.height / d->n_line > (float)d->win.width / maxS)
		return (d->win.width / maxS);
	return (d->win.height / d->n_line);
}

void	full_sq(t_data* d, int x, int y, int color){
	int xm;
	int ym;

	ym = 0;
	while (ym < d->sq_size)	
	{
		xm = 0;
		while (xm < d->sq_size)	
		{
			my_mlx_pixel_put(d, x * d->sq_size + xm, y * d->sq_size + ym, color);
			xm++;
		}
		ym++;
	}
}

void	empty_sq(t_data* d, int x, int y, int color){
	int xm;
	int ym;

	xm = 0;
	while (xm < d->sq_size)	
	{
		my_mlx_pixel_put(d, x * d->sq_size + xm, y * d->sq_size, color);
		my_mlx_pixel_put(d, x * d->sq_size + xm, y * d->sq_size + d->sq_size, color);
		xm++;
	}
	ym = 0;
	while (ym < d->sq_size)	
	{
		my_mlx_pixel_put(d, x * d->sq_size , y * d->sq_size + ym, color);
		my_mlx_pixel_put(d, x * d->sq_size + d->sq_size, y * d->sq_size + ym, color);
		ym++;
	}
}

int	in_circle(double x, double y, double diam){
	double	xyc;

	xyc = diam / 2;
	return (sqrt((pow(xyc - x, 2) + pow(xyc - y, 2))) < diam/2);
}

void	render_player(t_data* d, int x, int y, int color){
	int xm;
	int ym;

	ym = 0;
	while (ym < d->sq_size)	
	{
		xm = 0;
		while (xm < d->sq_size)	
		{
			if (in_circle(xm, ym, d->sq_size))
				my_mlx_pixel_put(d, x * d->sq_size + xm, y * d->sq_size + ym, color);
			xm++;
		}
		ym++;
	}
}


void	render_map(t_data* d){
	int x;
	int y;

	y = 0;
	while (d->map[y]){
		x = 0;
		while (d->map[y][x]){
			if (d->map[y][x] == '1')
				full_sq(d, x, y, 255);
			else
				full_sq(d, x, y, 0xFFFFFF);
			empty_sq(d, x, y, 0xA9ACA7);
			x++;
		}
		y++;
	}
	render_player(d, d->play.y, d->play.x, 0xEB2332);
}