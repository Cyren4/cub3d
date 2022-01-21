/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:10:18 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/21 21:09:25 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_map(t_data *d, int i)
{
    int j;
    
    j = i;
    while(d->file[i])
    {
        while(is_whitespace(*d->file[i]))
            i++;
        check_char(d, d->file[i]);
        i++;
    }
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

//         /*checker si la map existe*/
//         /*checker si elle est bien fermée*/

// int ft_player_position(char **map, t_data *data)//sinon faire un strchr dans *line pour chaque lettre
// {
//     int *i;

//     i = 0;
//     while (map[*i])
//     {
//         if (map[*i] == 'N')
//         {
//             data->player = 'N';
//             return (&i);
//         }
//         if (map[*i] == 'S')
//         {
//             data->player = 'S';
//             return (&i);
//         }
//         if (map[*i] == 'W')
//         {
//             data->player = 'W';
//             return (&i);
//         }
//         if (map[*i] == 'E')
//         {
//             data->player = 'E';
//             return (&i);
//         }
//         i++;
//         return (MISSING_PLAYER);
//     }    
// }
// int ft_fill_map(char *line, t_data *data)
// {
//      /*copier la map dans un tableau à double entrée*/
//      char **map;
//      int x;
//      int y;
//      int i;

//      x = 0;
//      y = 0;

//      while (line[i])
//      {
//         if (ft_check_map != WRONG_CHARACTER)
//         {
//             //calculer la taille de mon tableau à double entrée
//             map[y] = ft_strdup(line);
//             y++;
//         }
//         else
//             printf("Error\n map is not properly defined.");
//      }
//      return (map);
// }

// void ft_flood_fill()

