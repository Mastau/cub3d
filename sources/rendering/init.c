/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:11:14 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/21 13:05:01 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <rendering.h>
#include <raycast.h>

void	init_keys_3d(t_cub *data)
{
	data->keys.w = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.d = 0;
	data->keys.left = 0;
	data->keys.right = 0;
	data->keys.sprint = 0;
}

void	init_window_info(mlx_window_create_info *info)
{
	*info = (mlx_window_create_info){0};
	info->title = "Cub3D";
	info->width = WIDTH;
	info->height = HEIGHT;
}

void	init_ray_data(t_ray_data *ray, double base_angle, int i, int nb_rays)
{
	double	angle_step;

	angle_step = FOV / (double)(nb_rays - 1);
	ray->base_angle = base_angle;
	ray->angle = base_angle - (FOV / 2.0) + (i * angle_step);
	while (ray->angle < 0)
		ray->angle += 360.0;
	while (ray->angle >= 360.0)
		ray->angle -= 360.0;
}

void	init_render_params(t_render_params *params, int i,
t_ray_data *ray, t_render_context *ctx)
{
	int	wall_height;

	wall_height = (int)((WALL_HEIGHT / (ray->distance_adjusted + 0.0001))
			* (HEIGHT / 1080.0));
	if (wall_height > HEIGHT * 3)
		wall_height = HEIGHT * 3;
	params->mlx = ctx->mlx;
	params->win = ctx->win;
	params->x = i;
	params->wall_height = wall_height;
	params->textures = ctx->textures;
	params->wall_x = ray->wall_x;
	params->wall_orientation = ray->wall_orientation;
	params->data = ctx->data;
}
