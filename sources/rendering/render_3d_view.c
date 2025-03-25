/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:39:39 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/25 08:45:35 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <rendering.h>
#include <raycast.h>

static void	calculate_distance(t_ray_data *ray, t_player *player)
{
	double	dx;
	double	dy;
	double	relative_angle;

	dx = player->pos.x - ray->intersection.x;
	dy = player->pos.y - ray->intersection.y;
	ray->distance = sqrt(dx * dx + dy * dy);
	relative_angle = fabs((ray->angle - ray->base_angle) * M_PI / 180.0);
	ray->correction_factor = cos(relative_angle);
	ray->distance_adjusted = ray->distance * ray->correction_factor;
}

static void	draw_wall(t_ray_data *ray, int i, t_render_context *ctx)
{
	t_render_params	params;

	init_render_params(&params, i, ray, ctx);
	draw_vertical_line(&params);
}

static void	process_ray(t_ray_data *ray, t_render_context *ctx, int i)
{
	ray_cast(ctx->data->player, ray->angle, &ray->hit, &ray->intersection);
	if (ray->hit)
	{
		calculate_distance(ray, ctx->data->player);
		determine_wall_orientation_part1(ray, ctx->data->player);
		draw_wall(ray, i, ctx);
	}
}

static void	render_ray(int i, t_render_context *ctx)
{
	t_ray_data	ray;

	init_ray_data(&ray, ctx->base_angle, i, WIDTH);
	process_ray(&ray, ctx, i);
}

void	render_3d_view(mlx_context mlx, mlx_window win,
t_cub *data, t_textures *textures)
{
	int					i;
	t_render_context	ctx;

	ctx.mlx = mlx;
	ctx.win = win;
	ctx.data = data;
	ctx.textures = textures;
	ctx.base_angle = get_base_angle(get_player_orientation(data));
	i = 0;
	while (i < WIDTH)
	{
		render_ray(i, &ctx);
		i++;
	}
}
