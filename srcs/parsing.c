/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:05 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/18 15:52:15 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct  s_text
{
    int *R;
    char *SO;
    char *WE;
    char *EA;
    char *NO;
    char *S;
    int *F;
    int *C;
}               t_text;

static init(t_text *text)
{
    text->R = NULL;
    text->SO = NULL;
    text->WE = NULL;
    text->EA = NULL;
    text->NO = NULL;
    text->S = NULL;
    text->C = NULL;
}

static int  all_good(t_text text)
{
    if (text.R == NULL || text.SO == NULL || text.WE == NULL|| text.EA == NULL\
        || text.NO == NULL || text.S == NULL || text.F == NULL || text.C == NULL)
        return (0);
    else
        return (1);
}

void    check_line(char *line, t_text *text)
{

}

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