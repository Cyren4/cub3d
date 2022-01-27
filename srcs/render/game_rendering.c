/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:51:56 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/27 11:43:58 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	renders each frame
*/
int	render_frame(t_data *d)
{
	mlx_put_image_to_window(d->win.mlx_ptr, d->win.win_ptr, d->img.img, 0, 0);
	return (1);
}