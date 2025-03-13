/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:18:24 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/13 16:23:19 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static double	calculate_perpendicular_distance(t_ray_params *params, int side)
{
	double	perp_wall_dist;

	if (side == 0)
		perp_wall_dist = (params->side_dist_x - params->delta_dist_x);
	else
		perp_wall_dist = (params->side_dist_y - params->delta_dist_y);
	return (perp_wall_dist);
}

static void	set_intersection_point(t_intersection_data *data)
{
	data->intersection->x = data->player->pos.x + data->ray_dir_x * data->dist;
	data->intersection->y = data->player->pos.y + data->ray_dir_y * data->dist;
}

void	calculate_intersection(t_ray_info *ray_info, int side)
{
	double				perp_wall_dist;
	t_intersection_data	data;

	perp_wall_dist = calculate_perpendicular_distance(ray_info->params, side);
	data.intersection = ray_info->intersection;
	data.player = ray_info->player;
	data.ray_dir_x = ray_info->ray_dir_x;
	data.ray_dir_y = ray_info->ray_dir_y;
	data.dist = perp_wall_dist;
	set_intersection_point(&data);
}
