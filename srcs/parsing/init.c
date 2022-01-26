/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:34:45 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/26 13:42:16 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init(t_data *d)
{
    ft_memset(d, 0, sizeof(d));
    d->floor = -1;
    d->ceiling = -1;
    d->txt.path_so = NULL;
    d->txt.path_ea = NULL;
    d->txt.path_no = NULL;
    d->txt.path_we = NULL;
}