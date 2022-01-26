/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:47:51 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/26 13:19:04 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// return 1 si erreur dans le parsing
int	launch_parse(int ac, char **av, t_data *data)
{
	int fd;
	int i;

	fd = 0;
	i = 0;
	open_file(&fd, ac, av);
	init(data);
	get_file(data, fd, 0);
	parse_infos(data);
	close(fd); // stocker le fd dans la struct pour le close des qu'on rencontre une erreur
	return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	t_data data;
	
	if (launch_parse(ac, av, &data))
		return (1);
	start_game(&data);
	return (0);
}