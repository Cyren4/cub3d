/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:25:45 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/24 14:33:31 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define L 6
#define C 13

int check(char **map, int x, int y)
{
	if (x == 0 && map[x][y] != '1')
		return (1);
	if (y == 0 && map[x][y] != '1')
		return(1);
	if (y == 6 && map[x][y] != '1')
		return (1);
	if (x == 13 && map[x][y] != '1')
		return (1);
	return (0);
}

static int check_side(char side)
{
	if (side == '0' || side == '1')
		return (0);
	return (1);
}

int check_adjacent(t_data *d, int x, int y)
{
	if (x <= 0 || check_side(d->map[x - 1][y] == 1))
		return (1);
	if (y >= L || check_side(d->map[x][y + 1]) == 1)
		return (1);
	if (x >= C || check_side(d->map[x + 1][y] == 1))
		return (1);
	if (y <= 0 || check_side(d->map[x][y - 1]) == 1)
		return (1);
	return (0);
}

void flood_fill(t_data *d, int x, int y)
{
	if (check(d->map, x, y) == 1)
		d->open_map = true;
	if (d->map[x][y] != '1')
	{
		if (check_adjacent(d, x , y) == 1)
		{
			if(d->open_map == true)
				return;
		}
	}
	if (d->map[x][y] == '0')
		d->map[x][y] = 2;
	flood_fill(d, x, y + 1);
	flood_fill(d, x, y - 1);
	flood_fill(d, x + 1, y);
	flood_fill(d, x - 1, y);
}
