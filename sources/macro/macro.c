/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:07:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/14 13:29:11 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void window_hook(int event, void* param)
{
    if(event == 0)
        mlx_loop_end((mlx_context)param);
}

void key_hook(int key, void* param)
{
    if(key == 41)
        mlx_loop_end((mlx_context)param);
}

void	test_macro(t_player *player, t_cub *data)
{
	(void)player;
	mlx_context mlx = mlx_init();

	mlx_window_create_info info = { 0 };
	info.title = "Test";
    info.width = 500;
    info.height = 500;
	data->mlx = &mlx;
	mlx_window win = mlx_new_window(*data->mlx, &info);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, mlx);
    mlx_loop(mlx);
}
