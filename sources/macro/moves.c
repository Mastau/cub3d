/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:12:12 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/25 14:17:29 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <utils.h>

static double	get_margin_direction(double new_pos, double current_pos)
{
	if (new_pos > current_pos)
		return (1);
	return (-1);
}

void	move_player_backward(t_cub *data, double speed)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;
	int		collision;

	new_x = data->player->pos.x - data->player->dir.x * speed;
	new_y = data->player->pos.y - data->player->dir.y * speed;
	check_x = new_x + WALL_MARGIN
		* get_margin_direction(new_x, data->player->pos.x);
	collision = check_collision(data, check_x, 0, 'x');
	if (!collision)
		data->player->pos.x = new_x;
	check_y = new_y + WALL_MARGIN
		* get_margin_direction(new_y, data->player->pos.y);
	collision = check_collision(data, 0, check_y, 'y');
	if (!collision)
		data->player->pos.y = new_y;
}

void	move_player_right(t_cub *data, double speed)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;
	int		collision;

	new_x = data->player->pos.x - data->player->dir.y * speed;
	new_y = data->player->pos.y + data->player->dir.x * speed;
	check_x = new_x + WALL_MARGIN
		* get_margin_direction(new_x, data->player->pos.x);
	collision = check_collision(data, check_x, 0, 'x');
	if (!collision)
		data->player->pos.x = new_x;
	check_y = new_y + WALL_MARGIN
		* get_margin_direction(new_y, data->player->pos.y);
	collision = check_collision(data, 0, check_y, 'y');
	if (!collision)
		data->player->pos.y = new_y;
}

void	move_player_left(t_cub *data, double speed)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;
	int		collision;

	new_x = data->player->pos.x + data->player->dir.y * speed;
	new_y = data->player->pos.y - data->player->dir.x * speed;
	check_x = new_x + WALL_MARGIN
		* get_margin_direction(new_x, data->player->pos.x);
	collision = check_collision(data, check_x, 0, 'x');
	if (!collision)
		data->player->pos.x = new_x;
	check_y = new_y + WALL_MARGIN
		* get_margin_direction(new_y, data->player->pos.y);
	collision = check_collision(data, 0, check_y, 'y');
	if (!collision)
		data->player->pos.y = new_y;
}

void	move_player_forward(t_cub *data, double speed)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;
	int		collision;

	new_x = data->player->pos.x + data->player->dir.x * speed;
	new_y = data->player->pos.y + data->player->dir.y * speed;
	check_x = new_x + WALL_MARGIN
		* get_margin_direction(new_x, data->player->pos.x);
	collision = check_collision(data, check_x, 0, 'x');
	if (!collision)
		data->player->pos.x = new_x;
	check_y = new_y + WALL_MARGIN
		* get_margin_direction(new_y, data->player->pos.y);
	collision = check_collision(data, 0, check_y, 'y');
	if (!collision)
		data->player->pos.y = new_y;
}
