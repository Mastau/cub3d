/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:34:18 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 18:35:06 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <macro.h>
#include <raycast.h>
#include <rendering.h>
#include <utils.h>

void	init_3d_rendering(t_cub *data)
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
	t_textures				textures;

	mlx = mlx_init();
	init_keys(data);
	init_window_info(&info);
	data->mlx = &mlx;
	win = mlx_new_window(*data->mlx, &info);
	data->win = &win;
	textures = load_textures(mlx, data);
	render_3d_view(mlx, win, data, &textures);
	mlx_set_fps_goal(mlx, 60);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, data);
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_press_hook, data);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, textures.no);
	mlx_destroy_image(mlx, textures.so);
	mlx_destroy_image(mlx, textures.we);
	mlx_destroy_image(mlx, textures.ea);
}
