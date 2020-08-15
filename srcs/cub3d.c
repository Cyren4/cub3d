/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:11 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/31 21:15:33 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	check_resol(int max_x, int max_y, t_conf *conf)
{
	int min_x;
	int min_y;

	min_x = 100;
	min_y = 70;
	if (conf->resol[0] > max_x)
		conf->resol[0] = max_x;
	else if (conf->resol[0] < min_x)
		conf->resol[0] = min_x;
	if (conf->resol[1] > max_y)
		conf->resol[1] = max_y;
	else if (conf->resol[1] < min_y)
		conf->resol[1] = min_y;
}

int start_win(t_conf *conf)
{
	int *x;
	int *y;

	if ((conf->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	mlx_get_screen_size(conf->mlx_ptr, x, y);
	check_resol(*x, *y, conf);
	if ((conf->win = mlx_new_window(conf->mlx_ptr, conf->resol[0], conf->resol[1], "Welcome")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop(conf->mlx_ptr);
	return (EXIT_SUCCESS);
}*/