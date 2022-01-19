/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:23:37 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/19 14:23:09 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **argv)
{
    int     fd;
    t_data  d;
    int i;

    fd = 0;
    i = 0;
    if (check_error(fd, ac, argv))
        return (1);
    puts("here");
    //init(&d, fd);
    ft_memset(&d, 0,sizeof(d));
    d.file = get_file(fd, 0);
    print_map(d.file);
    //parse_infos(infos, &data);
    //close(fd);
    //free_map(&d);
    return (0);
}