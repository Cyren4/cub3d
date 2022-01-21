/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:00:16 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/21 18:58:44 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_to_int(int r, int g, int b)
{
	int	red;
	int	green;
	int	blue;

	red = r & 0xFF;
	green = g & 0xFF;
	blue = b & 0xFF;
	return (r << 16 | g << 8 | b);
}


int get_color(char *line)
{
    int i;
    int r;
    int g;
    int b;
    char **rgb;

    i = 0;
    rgb = split_trim(line);
    while(rgb[i])
        i++;
    if (i == 3)
    {
        r = ft_atoi(rgb[0]);
        g = ft_atoi(rgb[1]);
        b = ft_atoi(rgb[2]);
    }
    free_array(rgb);
    if (ft_strnstr(",,", line, ft_strlen(line)))
        return (1);
    if (r < 0 || g < 0 || b < 0 || r > 255 || g >255 || b > 255)
        return (1);
    return(rgb_to_int(r, g, b));
}
