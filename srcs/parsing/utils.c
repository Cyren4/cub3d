/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:40:08 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/24 16:33:01 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



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


char **split_trim(char *line)
{
    char *trim;
    char **rgb;

    trim = ft_strtrim(line, " ");
    rgb = ft_split(trim, ',');
    free(trim);
    return (rgb);
}
