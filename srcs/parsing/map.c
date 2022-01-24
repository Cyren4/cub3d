/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:10:18 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/24 16:40:40 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_map(char **infos)
{
	int i = 0;
	
	while (infos[i])
    {
        printf("%d - %s\n", i, infos[i]);
        i++;
    }
}

void check_map(t_data *d, int i)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    d->map = &d->file[i];
    print_map(d->map);
    while(d->file[i])
    {
        while(is_whitespace(*d->file[i]))
            i++;
        check_char(d, d->file[i]);
        i++;
    }
    find_player(d);
    //print_map(d->map);
}

void check_char(t_data *d, char *line)
{
    int i;

    i = 0;
    while (line[i])
    {     
        if (!ft_strchr(VALID_CHAR, line[i]))
        {
            printf("there's a forgiven character\n");
            free_exit(d);
        }
        i++;
    }
}
/**
 * @brief find player and stock it
 * (and replace spaces by 0)
 * 
 * @param
 */
void    find_player(t_data *d)
{
    int player;
    int x;
    int y;
    
    x = 0;
    y = 0;
    player = 0;
    while(d->map[x])
    {
        y = 0;
        while(d->map[x][y])
        {
            if (d->map[x][y] == ' ')
                d->map[x][y] = '0';
            if (ft_strchr(DIRECTIONS, d->map[x][y]))
            {   
                d->map[x][y] = '0';
                d->play.x = x;
                d->play.y = y;
                player++;
            }
            y++;
        }
        x++;
    }
    if (player != 1)
    {
        printf("Program require one player, with his orientation\n");
        free_exit(d);
    }
}
