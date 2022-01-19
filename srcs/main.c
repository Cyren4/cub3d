/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:23:37 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/19 16:09:53 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **argv)
{
    int     fd;
    t_data  data;
    int i;

    fd = 0;
    i = 0;
    fd = check_file(fd, ac, argv);
    init(&data);
    get_file(&data, fd, 0);
    print_map(data.file);
    parse_infos(infos, &data);
    close(fd);
    free_map(&data);
    return (0);
}