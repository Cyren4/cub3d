/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:40:08 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/19 13:51:59 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_whitespace(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return(1);
    return(0);
}

int	free_map(t_data *d)
{
	int	i;

	i = 0;
	while (d->file[i])
	{
		free(d->file[i]);
		d->file[i] = NULL;
		i++;
	}
	free(d->file);
	return (0);
}