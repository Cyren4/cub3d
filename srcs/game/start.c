/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:35:55 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/25 16:50:20 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	game loop
	dispatch to handlers render_frame and key_hook 
*/
void	play_game(t_data *data)
{
	// mlx_loop_hook(data->win.mlx_ptr, render_frame, data);
	// mlx_key_hook(data->win.win_ptr, key_hook, data);
	mlx_hook(data->win.win_ptr, 17, (1L << 17), close_g, data);
	mlx_loop(data->win.mlx_ptr);
}

/*
	calls init_game
	creates image and gets it's adress
	calls textMap 
	calls play_game
*/
void start_game(t_data *data)
{
	data->win.mlx_ptr = mlx_init();
	data->win.width = SIZE_X;
	data->win.height = SIZE_Y;
	data->win.win_ptr = mlx_new_window(data->win.mlx_ptr, data->win.width,
									   data->win.height, "cub3D");
	data->img.img = mlx_new_image(data->win.mlx_ptr, data->win.width, data->win.height);
	play_game(data);
}
