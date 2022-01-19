/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:00:16 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/19 18:14:41 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_value(int c)
{
    if (c < 0 || c > 255) 
        return (0);
    return (1);
}

void get_color(char *line, int color)
{
    int i;
    char **col;

    i = 0;
    while(is_whitespace(line[i]))
        i++;
    col = ft_split(ft_strtrim(line, " "), ',');
    //check_value de col
    //transforme ca en int ou en hexa
    //stocke le dans ceiling/floor
    
}