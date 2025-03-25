/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_wall_orentation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:57:02 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/25 08:40:20 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <rendering.h>
#include <raycast.h>

void	determine_wall_orientation_part1(t_ray_data *ray, t_player *player)
{
	double	x_diff;
	double	y_diff;

	x_diff = ray->intersection.x - player->pos.x;
	y_diff = ray->intersection.y - player->pos.y;
	if (fabs(ray->intersection.x - round(ray->intersection.x)) < 0.00001)
	{
		if (x_diff > 0)
			ray->wall_orientation = 1;
		else
			ray->wall_orientation = 3;
		ray->wall_x = ray->intersection.y - floor(ray->intersection.y);
	}
	else if (fabs(ray->intersection.y - round(ray->intersection.y)) < 0.00001)
		determine_wall_orientation_part2(ray, y_diff);
	else
		determine_wall_orientation_part3(ray, x_diff, y_diff);
}

void	determine_wall_orientation_part2(t_ray_data *ray, double y_diff)
{
	if (y_diff > 0)
		ray->wall_orientation = 2;
	else
		ray->wall_orientation = 0;
	ray->wall_x = ray->intersection.x - floor(ray->intersection.x);
}

void	determine_wall_orientation_part3(t_ray_data *ray,
double x_diff, double y_diff)
{
	double	x_diff_rounded;
	double	y_diff_rounded;

	x_diff_rounded = fabs(ray->intersection.x - round(ray->intersection.x));
	y_diff_rounded = fabs(ray->intersection.y - round(ray->intersection.y));
	if (x_diff_rounded < y_diff_rounded)
	{
		if (x_diff > 0)
			ray->wall_orientation = 1;
		else
			ray->wall_orientation = 3;
		ray->wall_x = ray->intersection.y - floor(ray->intersection.y);
	}
	else
	{
		if (y_diff > 0)
			ray->wall_orientation = 2;
		else
			ray->wall_orientation = 0;
		ray->wall_x = ray->intersection.x - floor(ray->intersection.x);
	}
}
