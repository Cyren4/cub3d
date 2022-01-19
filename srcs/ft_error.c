/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:57:17 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/19 13:31:31 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_format(char *str, char *ext)
{
	while (*str != '.')
		str++;
	if (ft_strcmp(str, ext) == 0)
		return (0);
	return (1);
}

int check_error(int fd, int ac, char **argv)
{
    
    if (ac != 2 || check_format(argv[1], ".cub"))
    {
        printf("Error: program takes only one argument, a map with a .cub extension");
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("%s\n", strerror(errno));
        return(errno);
    }
    return (0);
}
