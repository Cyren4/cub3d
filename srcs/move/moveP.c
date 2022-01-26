/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveP.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:08:41 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/26 23:24:57 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
	draws player after deplacement
*/
void	majPlayer(t_data *g, int x, int y)
{
	(void)g;
	(void)x;
	(void)y;
	//add calculus to move player
	// if (x = -1 -> gauche)	
	// if (x = 1 -> droite)	
	// if (y = 1 -> avance)	
	// if (y = -1 -> recule)	
}

int	key_hook(int keycode, t_data *d)
{
	if (keycode == KEY_A)
		majPlayer(d, -1, 0);
	else if (keycode == KEY_W)
		majPlayer(d, 0, 1);
	else if (keycode == KEY_D)
		majPlayer(d, 1, 0);
	else if (keycode == KEY_S)
		majPlayer(d, 0, -1);
	else if (keycode == KEY_ESC)
		close_g(d);
	return (keycode);
}