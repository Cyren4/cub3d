/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:57:17 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/26 11:34:25 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_format(char *str, char *ext)
{
	while (*str != '.')
		str++;
	if (ft_strcmp(str, ext) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int open_file(int *fd, int ac, char **argv)
{
    
    if (ac != 2 || check_format(argv[1], ".cub"))
    {
        printf("Error: program takes one argument, a map with a .cub extension");
        exit (1);
    }
    *fd = open(argv[1], __O_DIRECTORY);
    if (*fd != -1)
    {
        printf("Error: file is a directory");
        exit(1);
    }
    *fd = open(argv[1], O_RDONLY);
    if (*fd < 0)
    {
        printf("%s\n", strerror(errno));
        exit (errno);
    }
    return (*fd);
}

void	get_file(t_data *data, int fd, int lvl)
{
	char	*line;

	line = NULL;
	if (get_next_line(fd, &line) == 1)
		get_file(data, fd, lvl + 1);
	else
	{
		data->file = malloc(sizeof(char *) * (lvl + 2));
		data->file[lvl + 1] = NULL;
		data->file[lvl] = line;
	}
	data->file[lvl] = line;
}
