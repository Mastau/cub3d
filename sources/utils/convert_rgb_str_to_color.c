/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_str_to_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:17:06 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 17:19:54 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

unsigned int convert_rgb_str_to_color(char *rgb_str)
{
    int r, g, b;
    char **split;
    unsigned int color;

    split = ft_split(rgb_str, ',');
    if (!split || !split[0] || !split[1] || !split[2])
        return (0xFF000000); // Noir en cas d'erreur

    r = ft_atoi(split[0]);
    g = ft_atoi(split[1]);
    b = ft_atoi(split[2]);

    // Libérer la mémoire des split
    int i = 0;
    while (split[i])
        lp_free(split[i++]);
    lp_free(split);

    // Créer la couleur RGBA (alpha à 255)
    color = ((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | 0xFF;

    return color;
}
