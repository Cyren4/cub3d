/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:23:37 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/22 17:07:29 by ldes-cou         ###   ########.fr       */
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
    open_file(&fd, ac, argv);
    ft_memset(&data, 0,sizeof(data));
    get_file(&data, fd, 0);
    //print_map(data.file);
    parse_infos(&data);
    free_array(data.file);
    //print_map(data.map);
    close(fd); // stocker le fd dans la struct pour le close des qu'on rencontre une erreur
    //free_exit(&data);
    return (0);
}