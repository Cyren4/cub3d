/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:51:56 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/25 16:57:08 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	returns a pixel color	
*/
unsigned int	get_col(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

/*
	draws textures at (x,y)	in img
*/
// void	my_mlx_pixel_put(t_data *img, int x, int y, t_data *text)
// {
// 	char	*dst;
// 	int		xm;
// 	int		ym;

// 	text->addr = mlx_get_data_addr(text->img, &text->bits_pixel,
// 			&text->line_l, &text->endian);
// 	ym = y;
// 	while (ym < y + IMG_SIZE)
// 	{
// 		xm = x;
// 		while (xm < x + IMG_SIZE)
// 		{
// 			dst = img->addr + (ym * img->line_l + xm * (img->bits_pixel / 8));
// 			*(unsigned int *)dst = get_col(text, xm - x, ym - y);
// 			xm++;
// 		}
// 		ym++;
// 	}
// }

/*
	renders each frame
*/
int	render_frame(t_data *d)
{
	mlx_put_image_to_window(d->win.mlx_ptr, d->win.win_ptr, d->img.img, 0, 0);
	return (1);
}