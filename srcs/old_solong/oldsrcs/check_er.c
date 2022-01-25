/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_er.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 02:38:38 by cramdani          #+#    #+#             */
/*   Updated: 2020/06/01 17:04:01 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  equal(int *check, int equi)
{
    return (check[0] == equi || check[1] == equi || check[2] == equi ||\
        check[3] == equi || check[4] == equi || check[5] == equi ||\
        check[6] == equi || check[7] == equi);
}

static void invalid(int *check, int miss)
{
    if (check[0] == miss)
        write(1, "- Resolution\n", 14);
    if (check[1] == miss)
        write(1, "- South\n", 9);
    if (check[2] == miss)
        write(1, "- West\n", 8);
    if (check[3] == miss)
        write(1, "- East\n", 8);
    if (check[4] == miss)
        write(1, "- North\n", 9);
    if (check[5] == miss)
        write(1, "- Split\n", 9);
    if (check[6] == miss)
        write(1, "- Floor\n", 9);
    if (check[7] == miss)
        write(1, "- Ceiling\n", 11);
}

int     error_message(int *check, int end)
{
    int ret;

    if (equal(check, 0) == 1)
        {
            write(1, "Error\nFollowing textures are missing:\n", 39);
            invalid(check, 0);
        }
    if (equal(check, 2) == 1)
        {
            write(1, "Error\nDuplicate textures:\n", 27);
            invalid(check, 2);
        }
    if (equal(check, -1) == 1)
        {
            write(1, "Error\nFollowing textures are not valid:\n", 41);
            invalid(check, -1);
        }
    if (end == 0)
        write(1, "Error\nNo map found\n", 20);
    else if (end == -1)
        write(1, "Error\nProblem while reading file\n", 34);
    return (-1);
}