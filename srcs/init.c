/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:34:45 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/19 15:33:42 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init(t_data *d)
{
	ft_memset(d, 0,sizeof(d));
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

