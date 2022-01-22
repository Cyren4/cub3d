/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:25:45 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/22 20:48:18 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define L 8
#define C 13

int flood_fill(t_data *d, int x, int y)
{
	//printf("[%i]\n", x);
	//printf("[%i]\n", y);
	if (x <= 0 || y <=  0 || x >= C || y <= L)
		return (1);
	if (d->copy[x][y] == 1 || d->copy[x][y] == 2)
	{
		return(0);
	}
	if (d->copy[x][y] != 2)
	{
		if (d->copy[x][y] == ' ')
		{
			d->copy[x][y] = '0';
			return(0);
		}
	}
	if (d->copy[x][y] == '\0')
		return(1);
	d->copy[x][y] = 2;
	flood_fill(d, x, y + 1);
	flood_fill(d, x, y - 1);
	flood_fill(d, x + 1, y);
	flood_fill(d, x - 1, y);
	return(0);
}
