/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:45:49 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 12:44:51 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <raycast.h>

static void	init_ray_direction(double angle, t_player *player,
double *ray_dir_x, double *ray_dir_y)
{
	double	ray_angle;

	ray_angle = atan2(player->dir.y, player->dir.x) + degree_to_radian(angle);
	*ray_dir_x = cos(ray_angle);
	*ray_dir_y = sin(ray_angle);
}

static int	perform_dda(t_player *player, t_ray_params *p)
{
	int	side;

	side = 0;
	while (p->map_x >= 0 && p->map_x < player->map_width
		&& p->map_y >= 0 && p->map_y < player->map_height)
	{
		if (p->side_dist_x < p->side_dist_y)
		{
			p->side_dist_x += p->delta_dist_x;
			p->map_x += p->step_x;
			side = 0;
		}
		else
		{
			p->side_dist_y += p->delta_dist_y;
			p->map_y += p->step_y;
			side = 1;
		}
		if (p->map_y < player->map_height && p->map_x < player->map_width
			&& p->map_y >= 0 && p->map_x >= 0
			&& player->map[p->map_y][p->map_x] == '1')
			return (side);
	}
	return (-1);
}

void	ray_cast(t_player *player, double angle, int *hit,
t_vector *intersection)
{
	t_ray_info		ray_info;
	int				side;

	ray_info.player = player;
	ray_info.intersection = intersection;
	init_ray_direction(angle, player, &ray_info.ray_dir_x, &ray_info.ray_dir_y);
	ray_info.params = lp_alloc(sizeof(t_ray_params));
	init_ray_steps(player, ray_info.ray_dir_x, ray_info.ray_dir_y,
		ray_info.params);
	side = perform_dda(player, ray_info.params);
	if (side >= 0)
	{
		*hit = 1;
		calculate_intersection(&ray_info, side);
	}
	else
		*hit = 0;
	lp_free(ray_info.params);
}
