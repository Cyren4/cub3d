/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:11 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/24 10:44:15 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_win(int max_x, int max_y, t_data *data)
{
	int min_x;
	int min_y;

	min_x = 100;
	min_y = 70;
	if (data->win_size_x > max_x)
		data->win_size_x = max_x;
	else if (data->win_size_x < min_x)
		data->win_size_x = min_x;
	if (data->win_size_y > max_y)
		data->win_size_y = max_y;
	else if (data->win_size_y < min_y)
		data->win_size_y = min_y;
}

int start_win(void)
{
	t_data *data;
	int *x;
	int *y;

	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	mlx_get_screen_size(data->mlx_ptr, x, y);
	check_win(*x, *y, data);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->win_size_x, data->win_size_y, "Welcome")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop(data->mlx_ptr);
	return (EXIT_SUCCESS);
}