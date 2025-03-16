/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:07:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 15:06:05 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void test_macro(t_player *player, t_cub *data)
{
    mlx_context mlx = mlx_init();

    mlx_window_create_info info = { 0 };
    info.title = "Test";
    info.width = 1200;
    info.height = 500;
    data->mlx = &mlx;
    mlx_window win = mlx_new_window(*data->mlx, &info);

    // Passer le joueur à draw_map pour dessiner les rayons
    draw_map(mlx, win, data, player);

    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, mlx);
    mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, mlx);
    mlx_loop(mlx);
}
