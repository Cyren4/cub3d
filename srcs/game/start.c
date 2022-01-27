/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:35:55 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/27 11:51:36 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	game loop
	dispatch to handlers render_frame and key_hook 
*/
void	play_game(t_data *data)
{
	mlx_loop_hook(data->win.mlx_ptr, render_frame, data);
	mlx_key_hook(data->win.win_ptr, key_hook, data);
	mlx_hook(data->win.win_ptr, 17, (1L << 17), close_g, data);
	mlx_loop(data->win.mlx_ptr);
}

void	init_player(t_data *d){
	d->play.dirX = -1;
	d->play.dirY = 0;
	d->play.planeX = 0;
	d->play.planeY = 0.66;
}

t_img	*init_text(t_data *d)//add test if a mlx_xpm_file_to_image + if malloc fails render color cub3d default
{
	int		gab[2];
	t_img	*text;
	
	text = malloc(sizeof(t_img) * 4);
	if (!text)
		return NULL;
	text[NO].img = mlx_xpm_file_to_image(d->win.mlx_ptr, d->txt.path_no, &gab[0], &gab[1]);
	text[SO].img = mlx_xpm_file_to_image(d->win.mlx_ptr, d->txt.path_so, &gab[0], &gab[1]);
	text[EA].img = mlx_xpm_file_to_image(d->win.mlx_ptr, d->txt.path_ea, &gab[0], &gab[1]);
	text[WE].img = mlx_xpm_file_to_image(d->win.mlx_ptr, d->txt.path_we, &gab[0], &gab[1]);
	return text;
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
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	data->sq_size = get_square(data);
	init_player(data);
	data->txt.text = init_text(data);
	render_map(data);
	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, data->img.img, 0, 0);
	mlx_loop(data->win.mlx_ptr);
	play_game(data);
	
}
