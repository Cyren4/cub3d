/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:05:59 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/25 19:12:09 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int      all_good(int *conf)
{
    int i;

    i = 0;
    while (i < 8 && conf[i] != NULL)
    {
        if (conf[i] != 1)
            return (0);
        ++i;
    }
    return (1);
}

static int  clear(char **sep, int ret)
{
    int i;

	i = 0;
	while (sep[i] != NULL)
	{
		free(sep[i]);
		i++;
	}
    free(sep);
    return (ret);
}

int         text(char **sep, char *text, int *all_c, int i)
{
    if (sep[2] != NULL)
        return (clear(sep, -1));

    text = ft_strdup(sep[1]);
    if (text == NULL)
        return (clear(sep, -1));
    else
    {
        all_c[i] = 1;
        return (clear(sep, 1));
    }
}

int         res(char **sep, int *resol, int *all_c, int i)
{
    if (sep[2] == NULL && ft_isnum(sep[1]) == 1 && ft_isnum(sep[2]) == 1)
    {
            resol[0] = ft_atoi(sep[1]);
            resol[1] = ft_atoi(sep[2]);
            all_c[i] = 1;
            return (clear(sep, 1));
    }
    else
        return (clear(sep, -1));
}

int         color(char **sep, int *color, int *all_c, int i)
{
    char **num;
    int i;

    i = 0;
    if (sep[2] != NULL)
        return (clear(sep, -1));
    else
        num = ft_split(sep[1], ',');
    clear(sep, 1);
    if (num[4] == NULL && ft_isnum(num[0]) == 1 && ft_isnum(num[2]) == 1 &&\
        ft_isnum(num[3]))
    {
        while (i++ < 3)
            color[i] = ft_atoi(num[i]);
        all_c[i] = 1;
        return (clear(num, 1));
    }
        return (clear(num, -1));
}