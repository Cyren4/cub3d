/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_er.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 02:38:38 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/30 18:01:25 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void  invalid(int *check, int miss)
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

int     error_message(int *check)
{
    int ret;

    if (check[0] == 0 || check[1] == 0 || check[2] == 0 || check[3] == 0 ||\
        check[4] == 0 || check[5] == 0 || check[6] == 0 || check[7] == 0)
        {
            write(1, "Error\nFollowing textures are missing:\n", 39);
            invalid(check, 0);
        }
    if (check[0] == 2 || check[1] == 2 || check[2] == 2 || check[3] == 2 ||\
        check[4] == 2 || check[5] == 2 || check[6] == 2 || check[7] == 2)
        {
            write(1, "Error\nDuplicate textures:\n", 27);
            invalid(check, 2);
        }
    if (check[1] == -1 || check[2] == -1 || check[3] == -1  || check[4] == -1 \
        || check[5] == -1 || check[6] == -1 || check[7] == -1)
        {
            write(1, "Error\nFollowing textures are not valid:\n", 41);
            invalid(check, -1);
        }
    return (-1);
}