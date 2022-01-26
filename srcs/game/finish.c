/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:58 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/27 00:08:42 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



/*
	closes the game properly
	calls clear_g
*/
int	close_g(t_data *d)
{
	int	i;

	i = 0;
	write(1, "Game Over\n", 10);
	if (d->win.mlx_ptr)
	{
		if (d->win.win_ptr)
			mlx_destroy_window(d->win.mlx_ptr, d->win.win_ptr);
		mlx_destroy_image(d->win.mlx_ptr, d->img.img);
		// mlx_destroy_display(d->win.mlx_ptr); // voir pq pas trouve
	}
	free(d->win.mlx_ptr);
	free_exit(d);
	exit(EXIT_SUCCESS);
	return (0);
}