/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:40:08 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/21 10:55:45 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **build_array(void)
{
	char **directions;
	
	directions = malloc((sizeof(char *) * 4) + 1);
	directions[0] = ft_strdup("NO");
	directions[1] = ft_strdup("SO");
	directions[2] = ft_strdup("EA");
	directions[3] = ft_strdup("WE");
	return (directions);
}

int is_in_array(char **array, char *str)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (!ft_strcmp(array[i], str))
			return (i);
		i++;
	}
	return(-1);
}

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