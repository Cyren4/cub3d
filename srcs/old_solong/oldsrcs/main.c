/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 11:55:25 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/31 11:55:26 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_conf  conf;
    t_map   map;
	int	check;

	if ((check = check_name_file(ac, av)) > 0)
	{
		if (check_cub(av[1], &conf, &map) == 1)
			write(1, check == 2 ? "screen\n" : "play\n", check == 2 ? 8 : 6);
	}
//	system("leaks a.out");
	return (0);
}