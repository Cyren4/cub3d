/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:28:53 by Sophie            #+#    #+#             */
/*   Updated: 2021/03/30 16:30:00 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#define WINDOW_WIDTH 600

#define WINDOW_HEIGHT 300


#define MLX_ERROR 1


#define RED_PIXEL 0x00FF0000
#define GREEN_PIXEL 0xFF006622
#define	WHITE_PIXEL 0xFFFAFA

typedef struct s_rect
{
	int x;
	int y;
	int height;
	int width;
	int color;
}				t_rect;

void	render_background(t_data *data, int color)

{

	int	i;

	int	j;


	if (data->win == NULL)

		return ;

	i = 0;

	while (i < WINDOW_HEIGHT)

	{

		j = 0;

		while (j < WINDOW_WIDTH)

			mlx_pixel_put(data->mlx, data->win, j++, i, color);

		++i;

	}

}
int	display_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;
	
	if (data->win != NULL)
	{
		i = rect.y;
		while (i < rect.y + rect.height)
		{
			j = rect.x;
			while (j < rect.x + rect.width)
				mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
			i++;
		}
	}
	return (0);
}

int display(t_data *data)
{
		render_background(data, WHITE_PIXEL);
		display_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
		display_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
		return (0);
}
int	handle_keypress(int keysym, t_data *data)

{

	if (keysym == XK_Escape)

	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		
	}
	return (0);
}

int             main(void)
{	
	t_data	data;
	
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Ouh yeaah");
	if (data.win == NULL)
	{
		free(data.mlx);
		return (MLX_ERROR);
	}		
	mlx_loop_hook(data.mlx, &display, &data); 
	mlx_key_hook(data.win, &handle_keypress, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx_ptr);
	free (data.mlx);
}


