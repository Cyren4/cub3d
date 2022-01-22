/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:44:38 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/22 19:42:58 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_exit(t_data *d)
{
    if (d->file)
        free_array(d->file);
    if (d->copy)
        free_array(d->copy);
    ft_memdel(&d->txt.path_so);
    ft_memdel(&d->txt.path_ea);
    ft_memdel(&d->txt.path_no);
    ft_memdel(&d->txt.path_we);
    // if (d != NULL)
    // {
    //     free(d);
    //     d = NULL;
    // }
    exit(1);
}