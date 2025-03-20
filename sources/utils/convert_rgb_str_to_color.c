/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_str_to_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:17:06 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 18:23:38 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static unsigned	int	create_color_from_rgb(int r, int g, int b)
{
	unsigned int	color;

	color = ((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | 0xFF;
	return (color);
}

unsigned int	convert_rgb_str_to_color(char *rgb_str)
{
	int		r;
	int		g;
	int		b;
	char	**split;
	int		i;

	split = ft_split(rgb_str, ',');
	if (!split || !split[0] || !split[1] || !split[2])
		return (0xFF000000);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	i = 0;
	while (split[i])
		lp_free(split[i++]);
	lp_free(split);
	return (create_color_from_rgb(r, g, b));
}
