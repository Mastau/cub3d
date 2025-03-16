/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_orientation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:14:28 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 14:40:55 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

char	get_player_orientation(t_cub *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				return (data->map[y][x]);
			x++;
		}
		y++;
	}
	return ('N');
}

double	get_base_angle(char orientation)
{
	if (orientation == 'N')
		return (0.0);
	if (orientation == 'S')
		return (180.0);
	if (orientation == 'E')
		return (90.0);
	if (orientation == 'W')
		return (270.0);
	return (0.0);
}
