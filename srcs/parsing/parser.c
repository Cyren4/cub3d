/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:30:53 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/26 14:24:58 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// correct fonction to test paths
char *test_path(char *str)
{
    char *path;
    int fd;
    int i;

    path = NULL;
    i = 0;
    while(is_whitespace(str[i]))
        i++;
    fd = open(&str[i], O_RDONLY);
    {
        if (fd == -1)
            return(NULL);
    }
    path = ft_strdup(&str[i]);
    return (path);
}
void get_path(int path, t_data *d, char *str)
{
    int i;

    i = 0;
    while (str[i] && is_whitespace(str[i]))
        i++;
    if (path == NO)
        d->txt.path_no = test_path(&str[i + 2]);
    else if (path == SO)
        d->txt.path_so = test_path(&str[i + 2]);
    else if (path == EA)
        d->txt.path_ea = test_path(&str[i + 2]);
    else if (path == WE)
        d->txt.path_we = test_path(&str[i + 2]);
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
    if (d->ceiling < 0|| d->floor < 0)
        exit_error("Error: wrong color", d);
    if (d->txt.path_we == NULL || d->txt.path_ea == NULL 
        || d->txt.path_no == NULL || d->txt.path_so == NULL)
    // {
    //     printf("No = %s\n", d->txt.path_no);
    //     printf("So = %s\n", d->txt.path_so);
    //     printf("Ea = %s\n", d->txt.path_ea);
    //     printf("We = %s\n", d->txt.path_we);
        exit_error("Error: wrong texture path", d);
    //}
    check_map(d, i);
}

int check_infos(t_data *d)
{
    if (d->ceiling == -1 || d->floor == -1)
        return (EXIT_FAILURE);
    if (d->txt.path_we == NULL || d->txt.path_ea == NULL 
        || d->txt.path_no == NULL || d->txt.path_so == NULL)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
