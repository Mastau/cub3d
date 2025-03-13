/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:54:30 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/13 16:25:50 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	calculate_delta_dist(double ray_dir_x, double ray_dir_y,
t_ray_params *params)
{
	if (ray_dir_x == 0)
		params->delta_dist_x = 1e30;
	else
		params->delta_dist_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		params->delta_dist_y = 1e30;
	else
		params->delta_dist_y = fabs(1 / ray_dir_y);
}

static void	setup_x_direction(t_player *player, double ray_dir_x,
t_ray_params *params)
{
	if (ray_dir_x < 0)
	{
		params->step_x = -1;
		params->side_dist_x = (player->pos.x - params->map_x)
			* params->delta_dist_x;
	}
	else
	{
		params->step_x = 1;
		params->side_dist_x = (params->map_x + 1.0 - player->pos.x)
			* params->delta_dist_x;
	}
}

static void	setup_y_direction(t_player *player, double ray_dir_y,
t_ray_params *params)
{
	if (ray_dir_y < 0)
	{
		params->step_y = -1;
		params->side_dist_y = (player->pos.y - params->map_y)
			* params->delta_dist_y;
	}
	else
	{
		params->step_y = 1;
		params->side_dist_y = (params->map_y + 1.0 - player->pos.y)
			* params->delta_dist_y;
	}
}

void	init_ray_steps(t_player *player, double ray_dir_x, double ray_dir_y,
t_ray_params *params)
{
	calculate_delta_dist(ray_dir_x, ray_dir_y, params);
	params->map_x = (int)player->pos.x;
	params->map_y = (int)player->pos.y;
	setup_x_direction(player, ray_dir_x, params);
	setup_y_direction(player, ray_dir_y, params);
}
