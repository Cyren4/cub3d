/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:28:53 by Sophie            #+#    #+#             */
/*   Updated: 2021/03/26 11:55:35 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#define MLX_ERROR 1


int	display(t_data *data)
{
	int	x;
	int	y;
	
	x = 200;
	y = 200;

	if (data->win != NULL)
	{
		while (y < 400)
		{
			while (x < 400)
			{
				mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
				x++;
			}
		y++;
		}
	}
	return (0);
}		
int             key_hook(int keycode, t_data *data)
{
	
	ft_putnbr_fd(keycode, 1);
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return(0);
}

int             main(void)
{	
	t_data	data;
	
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, 600, 600, "Ouh yeaah");
	if (data.win == NULL)
	{
		free(data.mlx);
		return (MLX_ERROR);
	}		
	mlx_loop_hook(data.mlx, &display, &data); 
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	free (data.mlx);
}

