/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:34:45 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/21 19:41:39 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init(t_data *d)
{
    //d = malloc(sizeof(t_data));
    //printf("[      %p]\n", d);
    //d->txt = malloc(sizeof(t_text));
	ft_memset(d, 0,sizeof(d));
    // printf("[avant %p]\n", d->txt.path_we);
    // d->txt.path_ea = NULL;
    // d->txt.path_no = NULL;
    // d->txt.path_so = NULL;
    // d->txt.path_we = NULL;
    // printf("[apres %p]\n", d->txt.path_we);
	//print_map(d->map);
}
void print_map(char **infos)
{
	int i = 0;
	
	while (infos[i])
    {
        printf("%d - %s\n", i, infos[i]);
        i++;
    }
}

