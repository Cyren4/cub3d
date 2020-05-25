/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_er.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 02:38:38 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/23 19:07:58 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    error_message(int nb)
{
    if (nb == 0) // erreur de fichier
        write(1, "Erreur\nFichier invalide", 24);
    else if (nb == 1) // R -> resolution
        write(1, "Erreur\nResolution invalide", 27);
    else if (nb == 2) // NO texture nord
        write(1, "Erreur\nTexture Nord invalide", 29);
    else if (nb == 3) // SO texture sud
        write(1, "Erreur\nTexture Sud invalide", 28);
    else if (nb == 4) // WE texture west
        write(1, "Erreur\nTexture Ouest invalide", 30);
    else if (nb == 5) // EA texture est
        write(1, "Erreur\nTexture Est invalide", 28);
    else if (nb == 6) // S texture sprite
        write(1, "Erreur\nTexture sprite invalide", 31);
    else if (nb == 7) // F couleur sol
        write(1, "Erreur\nCouleur sol invalide", 28);
    else if (nb == 8) // C couleur plafond
        write(1, "Erreur\nCouleur plafond invalide", 32);
    else if (nb == 9)
        write(1, "Erreur\nLa map n'est pas valide", 31);
}