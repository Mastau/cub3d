/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:45:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/17 12:29:44 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <minimap.h>

void	set_square_player(t_square_params *params, int pos_x, int pos_y)
{
	params->x = pos_x;
	params->y = pos_y;
	params->color = 0xFF0000FF;
}

void	draw_player(mlx_context mlx, mlx_window win, t_player *player)
{
	t_square_params	params;
	int				pos_x;
	int				pos_y;

	pos_x = 50 + (int)(player->pos.x * 30) - 15;
	pos_y = 50 + (int)(player->pos.y * 30) - 15;
	set_square_player(&params, pos_x, pos_y);
	draw_square(mlx, win, &params);
}
