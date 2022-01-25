/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:44:38 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/25 12:48:20 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_exit(t_data *d)
{
    free_array(d->file);
    ft_memdel(&d->txt.path_so);
    ft_memdel(&d->txt.path_ea);
    ft_memdel(&d->txt.path_no);
    ft_memdel(&d->txt.path_we);
    exit(1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array && array[i])
		{
			ft_memdel(&array[i]);
			i++;
		}
		free(array);
		array = NULL;
	}
}
