/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:35:55 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/25 15:52:33 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int start_game(t_data *data){
    t_img img;

    data->win.mlx_ptr = mlx_init();
    data->win.win_ptr = mlx_new_window(data->win.mlx_ptr, data->win.width,
                        data->win.height, "cub3D");
    img.img = mlx_new_image(data->win.mlx_ptr, data->win.width, data->win.height);
    data->img = img; 
    mlx_loop(data->win.mlx_ptr);
    return 1;
}