/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:35:55 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/25 16:36:19 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_game(t_data *data)
{
	(void)data;
}

void start_game(t_data *data)
{
	data->win.mlx_ptr = mlx_init();
	data->win.width = SIZE_X;
	data->win.height = SIZE_Y;
	data->win.win_ptr = mlx_new_window(data->win.mlx_ptr, data->win.width,
									   data->win.height, "cub3D");
	data->img.img = mlx_new_image(data->win.mlx_ptr, data->win.width, data->win.height);
	mlx_loop(data->win.mlx_ptr);
	play_game(data);
}