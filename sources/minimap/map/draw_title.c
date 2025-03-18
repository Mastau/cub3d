/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_title.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:12:58 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 19:48:03 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <minimap.h>

static void	set_square_wall(t_square_params *params, int pos_x, int pos_y)
{
	params->x = pos_x;
	params->y = pos_y;
	params->color = 0xFFFFFFFF;
}

static void	set_square_player(t_square_params *params, int pos_x, int pos_y)
{
	params->x = pos_x;
	params->y = pos_y;
	params->color = 0xFF0000FF;
}

void	draw_map_tile(mlx_context mlx, mlx_window win, t_cub *data,
int coords[2])
{
	int				pos_x;
	int				pos_y;
	int				x;
	int				y;
	t_square_params	params;

	x = coords[0];
	y = coords[1];
	pos_x = 50 + x * 30;
	pos_y = 50 + y * 30;
	if (data->map[y][x] == '1')
	{
		set_square_wall(&params, pos_x, pos_y);
		draw_square(mlx, win, &params);
	}
	else if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
		|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
	{
		set_square_player(&params, pos_x, pos_y);
	}
}

void	draw_map_tiles(mlx_context mlx, mlx_window win, t_cub *data)
{
	int	y;

	y = 0;
	while (data->map[y])
	{
		draw_map_row(mlx, win, data, y);
		y++;
	}
}
