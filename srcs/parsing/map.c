/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:10:18 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/26 14:19:22 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_adjacent(char **map, int x, int y, int line)
{
    if (x < 1 || y < 1 || x >= (line))
        return (EXIT_FAILURE);
    if (is_whitespace(map[x + 1][y]) || is_whitespace(map[x - 1][y]))
        return(EXIT_FAILURE);
    if (is_whitespace(map[x][y + 1]) || is_whitespace(map[x][y - 1]))
        return (EXIT_FAILURE);
    return(EXIT_SUCCESS);
}

bool is_map_open(char **map, int line)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while(map && map[x])
    {
        y = 0;
        while (map[x][y])
        {
            if (map[x][y] == '0')
            {
                if (check_adjacent(map, x , y, line) == EXIT_FAILURE)
                    return (true);
            }
            y++;
        }
        x++;
    }
    return(false);
}


void check_map(t_data *d, int i)
{
    int n_player;

    n_player = 0;
    d->map = &d->file[i];
    print_map(d->map);
    if (d->map == NULL)
        free_exit(d);
    while(d->file && d->file[i])
    {
        check_char(d, d->file[i]);
        i++;
    }
    n_player = find_player(d);
    if (n_player != 1)
        exit_error("Error: Not the right number of player", d);
    if (is_map_open(d->map, d->n_line) == true)
        exit_error("Error: Map is open", d);
}

void check_char(t_data *d, char *line)
{
    int i;

    i = 0;
    while (line[i])
    {     
        if (!ft_strchr(VALID_CHAR, line[i]))
            exit_error("Error: forbidden character", d);
        i++;
    }
}
/**
 * @brief find player and stock it
 * (and replace spaces by 0)
 * 
 * @param 
 */
int    find_player(t_data *d)
{
    int n_player;
    int x;
    int y;
    
    x = 0;
    y = 0;
    n_player = 0;
    while(d->map[x])
    {
        y = 0;
        while(d->map[x][y])
        {
            if (ft_strchr(DIRECTIONS, d->map[x][y]))
            {   
                d->map[x][y] = '0';
                d->play.x = x;
                d->play.y = y;
                n_player++;
            }
            y++;
        }
        x++;
    }
    d->n_line = x;
    return (n_player);
}
