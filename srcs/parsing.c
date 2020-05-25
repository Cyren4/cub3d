/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:05 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/25 19:12:53 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int         check_pre(int fd, char **line)
{
    int ret;
    t_text *text;

    init(text);
    while (((ret = get_next_line(fd, line)) > 0) && all_good(*text) != 1)
        check_line(*line, text);
    if (all_good(*text) != 1)
        write(1, "Error\nTexture is missing", 25);
    return (all_good(*text));
}