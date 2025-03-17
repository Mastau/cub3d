/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:19:19 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/17 14:51:53 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <minimap.h>

static void	update_x_position(int *pos, int *err_vals, int e2)
{
	if (e2 >= err_vals[2])
	{
		if (pos[0] == pos[2])
			return ;
		err_vals[0] += err_vals[2];
		if (pos[0] < pos[2])
			pos[0] += 1;
		else
			pos[0] -= 1;
	}
}

static void	update_y_position(int *pos, int *err_vals, int e2)
{
	if (e2 <= err_vals[1])
	{
		if (pos[1] == pos[3])
			return ;
		err_vals[0] += err_vals[1];
		if (pos[1] < pos[3])
			pos[1] += 1;
		else
			pos[1] -= 1;
	}
}

static void	draw_ray_step(mlx_context mlx, mlx_window win, int *pos,
int *err_vals)
{
	int	e2;

	mlx_pixel_put(mlx, win, pos[0], pos[1], (mlx_color){.rgba = 0xFFFF00FF});
	if (pos[0] == pos[2] && pos[1] == pos[3])
		return ;
	e2 = 2 * err_vals[0];
	update_x_position(pos, err_vals, e2);
	update_y_position(pos, err_vals, e2);
}

static void	set_ray_direction(int *err_vals, int *pos)
{
	if (pos[0] < pos[2])
		err_vals[4] = 1;
	else
		err_vals[4] = -1;
	if (pos[1] < pos[3])
		err_vals[5] = 1;
	else
		err_vals[5] = -1;
}

void	draw_ray(mlx_context mlx, mlx_window win, t_ray *params)
{
	int	err_vals[6];
	int	pos[4];

	pos[0] = params->start_x;
	pos[1] = params->start_y;
	pos[2] = params->end_x;
	pos[3] = params->end_y;
	err_vals[1] = abs(params->end_x - params->start_x);
	err_vals[2] = -abs(params->end_y - params->start_y);
	set_ray_direction(err_vals, pos);
	err_vals[0] = err_vals[1] + err_vals[2];
	while (1)
	{
		draw_ray_step(mlx, win, pos, err_vals);
		if (pos[0] == pos[2] && pos[1] == pos[3])
			break ;
	}
}
