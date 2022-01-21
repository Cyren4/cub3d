/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:40:08 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/21 20:57:05 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char **build_array(void)
// {
// 	char **directions;
	
// 	directions = NULL;
// 	directions = malloc((sizeof(char *) * 4) + 1);
// 	directions[0] = ft_strdup("NO");
// 	directions[1] = ft_strdup("SO");
// 	directions[2] = ft_strdup("EA");
// 	directions[3] = ft_strdup("WE");
// 	return (directions);
// }

int is_cardinal(char *line)
{
	int i;

	i = 0;
	if (line[i] == '\0')
		return(-1);
	while (is_whitespace(line[i]))
		i++;
	if (!ft_strncmp(line, "NO", 2))
		return (NO);
	else if (!ft_strncmp(line, "SO", 2))
		return (SO);
	else if (!ft_strncmp(line, "EA", 2))
		return (EA);
	else if (!ft_strncmp(line, "WE", 2))
		return (WE);
	return (-1);
}

int is_whitespace(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return(1);
    return(0);
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

char **split_trim(char *line)
{
    char *trim;
    char **rgb;

    trim = ft_strtrim(line, " ");
    rgb = ft_split(trim, ',');
    free(trim);
    return (rgb);
}
