/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:18:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/17 12:29:23 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <minimap.h>

void	draw_map_row(mlx_context mlx, mlx_window win, t_cub *data, int y)
{
	int	x;
	int	coords[2];

	x = 0;
	coords[1] = y;
	while (data->map[y][x])
	{
		coords[0] = x;
		draw_map_tile(mlx, win, data, coords);
		x++;
	}
}

void	draw_map(mlx_context mlx, mlx_window win, t_cub *data, t_player *player)
{
	char	orientation;
	double	base_angle;

	draw_map_tiles(mlx, win, data);
	draw_player(mlx, win, player);
	orientation = get_player_orientation(data);
	base_angle = get_base_angle(orientation);
	cast_and_draw_rays(mlx, win, player, base_angle);
}
