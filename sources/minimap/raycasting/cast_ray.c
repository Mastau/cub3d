/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:20:23 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 14:55:13 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <minimap.h>

static void	prepare_ray_params(t_ray_params *ray_params, t_player *player,
t_vector *intersection)
{
	ray_params->start_x = 50 + (int)(player->pos.x * 30);
	ray_params->start_y = 50 + (int)(player->pos.y * 30);
	ray_params->end_x = 50 + (int)(intersection->x * 30);
	ray_params->end_y = 50 + (int)(intersection->y * 30);
	ray_params->color = 0xFFFF00FF;
}

static void	cast_single_ray(mlx_context mlx, mlx_window win,
t_player *player, double angle)
{
	t_vector		intersection;
	int				hit;
	t_ray_params	ray_params;

	while (angle < 0)
		angle += 360.0;
	while (angle >= 360.0)
		angle -= 360.0;
	ray_cast(player, angle, &hit, &intersection);
	if (hit)
	{
		prepare_ray_params(&ray_params, player, &intersection);
		draw_ray(mlx, win, &ray_params);
	}
}

void	cast_and_draw_rays(mlx_context mlx, mlx_window win,
t_player *player, double base_angle)
{
	int		i;
	double	angle;
	int		nb_rayons;

	nb_rayons = 60;
	i = 0;
	while (i < nb_rayons)
	{
		angle = base_angle - (FOV / 2.0) + (i * FOV / (nb_rayons - 1));
		cast_single_ray(mlx, win, player, angle);
		i++;
	}
}
