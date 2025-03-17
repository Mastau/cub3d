/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:23:51 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/17 12:32:36 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	rotate_player_left(t_cub *data)
{
	double	old_dir_x;
	double	cos_rot;
	double	sin_rot;

	old_dir_x = data->player->dir.x;
	cos_rot = cos(-ROTATION_SPEED);
	sin_rot = sin(-ROTATION_SPEED);
	data->player->dir.x = data->player->dir.x
		* cos_rot - data->player->dir.y * sin_rot;
	data->player->dir.y = old_dir_x * sin_rot + data->player->dir.y * cos_rot;
}

void	rotate_player_right(t_cub *data)
{
	double	old_dir_x;
	double	cos_rot;
	double	sin_rot;

	old_dir_x = data->player->dir.x;
	cos_rot = cos(ROTATION_SPEED);
	sin_rot = sin(ROTATION_SPEED);
	data->player->dir.x = data->player->dir.x
		* cos_rot - data->player->dir.y * sin_rot;
	data->player->dir.y = old_dir_x * sin_rot + data->player->dir.y * cos_rot;
}
