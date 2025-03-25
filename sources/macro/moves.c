/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:23:17 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/21 12:06:41 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	move_player_backward(t_cub *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos.x - data->player->dir.x * speed;
	new_y = data->player->pos.y - data->player->dir.y * speed;
	if (data->player->map[(int)new_y][(int)new_x] != '1')
	{
		data->player->pos.x = new_x;
		data->player->pos.y = new_y;
	}
}

void	move_player_right(t_cub *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos.x - data->player->dir.y * speed;
	new_y = data->player->pos.y + data->player->dir.x * speed;
	if (data->player->map[(int)new_y][(int)new_x] != '1')
	{
		data->player->pos.x = new_x;
		data->player->pos.y = new_y;
	}
}

void	move_player_left(t_cub *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos.x + data->player->dir.y * speed;
	new_y = data->player->pos.y - data->player->dir.x * speed;
	if (data->player->map[(int)new_y][(int)new_x] != '1')
	{
		data->player->pos.x = new_x;
		data->player->pos.y = new_y;
	}
}

void	move_player_forward(t_cub *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos.x + data->player->dir.x * speed;
	new_y = data->player->pos.y + data->player->dir.y * speed;
	if (data->player->map[(int)new_y][(int)new_x] != '1')
	{
		data->player->pos.x = new_x;
		data->player->pos.y = new_y;
	}
}
