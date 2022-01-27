/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:28:55 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/27 11:42:58 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}


/*
	draws textures at (x,y)	in img
*/
void	my_mlx_image_put(t_data *d, int x, int y, t_img *text)
{
	char	*dst;
	int		xm;
	int		ym;

	text->addr = mlx_get_data_addr(text->img, &text->bpp,
			&text->line_len, &text->endian);
	ym = y;
	while (ym < y + d->sq_size)
	{
		xm = x;
		while (xm < x + d->sq_size)
		{
			dst = d->img.addr + (ym * d->img.line_len + xm * (d->img.bpp / 8));
			*(unsigned int *)dst = get_col(text, xm - x, ym - y);
			xm++;
		}
		ym++;
	}
}

/*
	returns a pixel color	
*/
unsigned int	get_col(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}