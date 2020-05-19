/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:11 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/18 14:41:42 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int main(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		write(1, "Erreur\n Arguments invalides", 28);
	if (check_map(av[1]) == 1)
	{
		cub3d(av[1]);
		if (ft_strcmp(av[2], "--save") == 0)
			screen_shot();
	}	
	else
		return(-1);
}
