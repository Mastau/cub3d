/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:34:18 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/21 14:16:04 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <macro.h>
#include <raycast.h>
#include <rendering.h>
#include <utils.h>

static void	render(t_cub *data)
{
	mlx_color	clear_color;

	clear_color = (mlx_color){{0, 0, 0, 255}};
	mlx_clear_window(*data->mlx, *data->win, clear_color);
	render_3d_view(*data->mlx, *data->win, data, data->textures);
}

static void	update_3d_view(void *param)
{
	t_cub	*data;
	double	current_speed;

	data = (t_cub *)param;
	current_speed = MOVE_SPEED;
	if (data->keys.sprint)
		current_speed = MOVE_SPEED * 2.0;
	if (data->keys.w)
		move_player_forward(data, current_speed);
	if (data->keys.s)
		move_player_backward(data, current_speed);
	if (data->keys.a)
		move_player_left(data, current_speed);
	if (data->keys.d)
		move_player_right(data, current_speed);
	if (data->keys.left)
		rotate_player_left(data);
	if (data->keys.right)
		rotate_player_right(data);
	if (data->keys.w || data->keys.s || data->keys.a
		|| data->keys.d || data->keys.left || data->keys.right)
		render(data);
}

void	init_3d_rendering(t_cub *data)
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
	t_textures				textures;

	mlx = mlx_init();
	init_keys_3d(data);
	init_window_info(&info);
	data->mlx = &mlx;
	win = mlx_new_window(*data->mlx, &info);
	data->win = &win;
	textures = load_textures(mlx, data);
	data->textures = &textures;
	render_3d_view(mlx, win, data, &textures);
	mlx_set_fps_goal(mlx, 60);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, data);
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_press_hook, data);
	mlx_on_event(mlx, win, MLX_KEYUP, key_release_hook, data);
	mlx_add_loop_hook(mlx, update_3d_view, data);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, textures.no);
	mlx_destroy_image(mlx, textures.so);
	mlx_destroy_image(mlx, textures.we);
	mlx_destroy_image(mlx, textures.ea);
}
