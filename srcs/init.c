/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:34:45 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/01/19 14:23:43 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init(t_data *d, int fd)
{
	(void)fd;
	ft_memset(d, 0,sizeof(d));
	//get_file(d, fd, 0);
	//print_map(d->map);
}
void print_map(char **infos)
{
	int i = 0;
	
	while (infos[i])
    {
        printf("%d - %s\n", i, infos[i]);
        i++;
    }
}

char    **get_file(int fd, int lvl)
{
    char *line;
    char **infos;

    line = NULL;
    if (get_next_line(fd, &line) == 1)
        infos = get_file(fd, lvl + 1);
    else
    {
        infos = malloc(sizeof(char*) * (lvl + 2));
        infos[lvl + 1] = NULL;
        infos[lvl] = line;
        return (infos);
    }
	puts("caca");
    infos[lvl] = line;
    return (infos);
}
