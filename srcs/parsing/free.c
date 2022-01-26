/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:44:38 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/27 00:09:55 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void free_exit(t_data *d)
{
    if (d->file != NULL)
        free_array(d->file);
    ft_memdel(&d->txt.path_so);
    ft_memdel(&d->txt.path_ea);
    ft_memdel(&d->txt.path_no);
    ft_memdel(&d->txt.path_we);
    free(d->txt.text);
    exit(EXIT_FAILURE);
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
