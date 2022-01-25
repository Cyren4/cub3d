/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:58 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/25 17:25:38 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
	clear t_game structure
*/
// void	clear_g(t_game *g)
// {
// 	free(g->mlx);
// 	clear_map(g->map);
// 	free(g->text);
// 	free(g);
// }

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
	free_exit(d);
	exit(EXIT_SUCCESS);
	return (0);
}