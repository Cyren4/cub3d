/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:30:53 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/25 15:59:23 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_path(int path, t_data *d, char *str)
{
    int i;

    i = 0;
    while (str[i] && is_whitespace(str[i]))
        i++;
    if (path == NO)
        d->txt.path_no = ft_strdup(&str[i]);
    else if (path == SO)
        d->txt.path_so = ft_strdup(&str[i]);
    else if (path == EA)
        d->txt.path_ea = ft_strdup(&str[i]);
    else if (path == WE)
        d->txt.path_we = ft_strdup(&str[i]);
        //test path ?
}

void parse_infos(t_data *d)
{
    int i;
    int path;

    i = 0;
    path = 0;
    while(d->file && d->file[i])
    {
        if (*d->file[i] == 'F')
            d->floor = get_color(d->file[i]);
        else if(*d->file[i] == 'C')
            d->ceiling = get_color(d->file[i]);
        else if (is_cardinal(d->file[i]) != -1)
        {
            path = is_cardinal(d->file[i]);
            get_path(path, d, d->file[i]);
        }
        i++;
        if (check_infos(d) == 0)
            break;
    }
    if (d->ceiling == 1|| d->floor == 1)
    {
        printf("Error : wrong color\n");
        free_exit(d);
    }
    check_map(d, i + 1);
}

int check_infos(t_data *d)
{
    if (d->ceiling < 2|| d->floor < 2)
        return (EXIT_FAILURE);
    else if (d->txt.path_we == NULL || d->txt.path_ea == NULL 
        || d->txt.path_no == NULL || d->txt.path_so == NULL)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
