/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:13:14 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 12:34:37 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static int	check_x_collision(t_cub *data, double x)
{
	int		check_x;
	int		check_y;
	double	y_frac;

	check_x = (int)x;
	check_y = (int)data->player->pos.y;
	if (data->player->map[check_y][check_x] == '1')
		return (1);
	y_frac = data->player->pos.y - check_y;
	if (y_frac < ANGLE_MARGIN && check_y > 0
		&& data->player->map[check_y - 1][check_x] == '1')
		return (1);
	if (y_frac > (1.0 - ANGLE_MARGIN)
		&& check_y + 1 < data->player->map_height
		&& data->player->map[check_y + 1][check_x] == '1')
		return (1);
	return (0);
}

static int	check_y_collision(t_cub *data, double y)
{
	int		check_x;
	int		check_y;
	double	x_frac;

	check_y = (int)y;
	check_x = (int)data->player->pos.x;
	if (data->player->map[check_y][check_x] == '1')
		return (1);
	x_frac = data->player->pos.x - check_x;
	if (x_frac < ANGLE_MARGIN && check_x > 0
		&& data->player->map[check_y][check_x - 1] == '1')
		return (1);
	if (x_frac > (1.0 - ANGLE_MARGIN)
		&& check_x + 1 < data->player->map_width
		&& data->player->map[check_y][check_x + 1] == '1')
		return (1);
	return (0);
}

int	check_collision(t_cub *data, double x, double y, char axis)
{
	if (axis == 'x')
		return (check_x_collision(data, x));
	return (check_y_collision(data, y));
}
