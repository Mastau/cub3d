/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:07:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/17 15:16:33 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <macro.h>

static void	init_keys(t_cub *data)
{
	data->keys.w = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.d = 0;
	data->keys.left = 0;
	data->keys.right = 0;
}

static void	init_window_info(mlx_window_create_info *info)
{
	*info = (mlx_window_create_info){0};
	info->title = "Minimap";
	info->width = 1000;
	info->height = 500;
}

void	minimap(t_cub *data)
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;

	mlx = mlx_init();
	init_keys(data);
	init_window_info(&info);
	data->mlx = &mlx;
	win = mlx_new_window(*data->mlx, &info);
	data->win = &win;
	draw_map(mlx, win, data, data->player);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, data);
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_press_hook, data);
	mlx_on_event(mlx, win, MLX_KEYUP, key_release_hook, data);
	mlx_add_loop_hook(mlx, update_game, data);
	mlx_loop(mlx);
}
