/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:17:50 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 15:01:20 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <minimap.h>

static void	draw_square_part(mlx_context mlx, mlx_window win,
int pos[2], int color)
{
	int	dx;
	int	i;
	int	x;
	int	y;

	i = 0;
	y = pos[1];
	while (i < 15)
	{
		dx = 0;
		x = pos[0];
		while (dx < 30)
		{
			mlx_pixel_put(mlx, win, x + dx, y, (mlx_color){.rgba = color});
			dx++;
		}
		y++;
		i++;
	}
}

void	draw_square(mlx_context mlx, mlx_window win, t_square_params *params)
{
	int	pos[2];

	pos[0] = params->x;
	pos[1] = params->y;
	draw_square_part(mlx, win, pos, params->color);
	pos[1] = params->y + 15;
	draw_square_part(mlx, win, pos, params->color);
}
