/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 19:03:36 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/25 15:00:14 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    get_out(int fd, int ret)
{
    close(fd);
    return(ret);
}

int     check_name_file(int ac, char **av)
{
    if (ac < 2 || ac > 3)
		write(1, ac < 2 ? "Error\nNot enough arguments\n" :\
            "Error\nToo many arguments\n", ac < 2 ? 28 : 26);
	else
    {
        if (strcmp((av[1] + strlen(av[1]) - 4), ".cub") != 0)
	        write(1, "Error\nThis program can't take other file than *.cub\n", 53);
        else if (ac == 3)
        {
            if (strcmp(av[2], "--save") != 0)
                write(1, "Error\nSecond argument invalid\n", 31);
            else //screenshot
                return (2);
        }
        else // all names are valid 
            return (1);
    }
    return (0);
}

int		main(int ac, char **av)
{
	t_conf  *conf;
    t_map   *map;
	int	check;

	if ((check = check_name_file(ac, av)) > 0)
	{
		if (check_cub(av[1], conf, map) == 1)
			check == 2 ? screenshot() : cub3d();
		
	}
	return (0);
}

/*int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac > 1)
	if (fd == -1)
		return (-1);
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		printf("%d |>>| %s\n", ret_value, line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);*/