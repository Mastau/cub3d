/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:02:32 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/21 11:51:39 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <macro.h>

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

void	key_press_hook(int key, void *param)
{
	t_cub	*data;

	data = (t_cub *)param;
	if (key == 41)
		mlx_loop_end(*data->mlx);
	else if (key == 26)
		data->keys.w = 1;
	else if (key == 22)
		data->keys.s = 1;
	else if (key == 4)
		data->keys.a = 1;
	else if (key == 7)
		data->keys.d = 1;
	else if (key == 80)
		data->keys.left = 1;
	else if (key == 79)
		data->keys.right = 1;
}

void	key_release_hook(int key, void *param)
{
	t_cub	*data;

	data = (t_cub *)param;
	if (key == 26)
		data->keys.w = 0;
	else if (key == 22)
		data->keys.s = 0;
	else if (key == 4)
		data->keys.a = 0;
	else if (key == 7)
		data->keys.d = 0;
	else if (key == 80)
		data->keys.left = 0;
	else if (key == 79)
		data->keys.right = 0;
}

static void	update_display(t_cub *data)
{
	mlx_color	clear_color;

	clear_color = (mlx_color){{0, 0, 0, 255}};
	mlx_clear_window(*data->mlx, *data->win, clear_color);
	draw_map(*data->mlx, *data->win, data, data->player);
}

void	update_game(void *param)
{
	t_cub	*data;

	data = (t_cub *)param;
	if (data->keys.w)
		move_player_forward(data);
	if (data->keys.s)
		move_player_backward(data);
	if (data->keys.a)
		move_player_left(data);
	if (data->keys.d)
		move_player_right(data);
	if (data->keys.left)
		rotate_player_left(data);
	if (data->keys.right)
		rotate_player_right(data);
	if (data->keys.w || data->keys.s || data->keys.a
		|| data->keys.d || data->keys.left || data->keys.right)
		update_display(data);
}
