/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:07:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 18:44:53 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void update_display(t_cub *data)
{
    // Effacer l'affichage précédent (ou redessiner avec la couleur de fond)
    mlx_color clear_color = {{0, 0, 0, 255}}; // Noir
    mlx_clear_window(*data->mlx, *data->win, clear_color);

    // Redessiner la carte et les rayons
    draw_map(*data->mlx, *data->win, data, data->player);

    // Si vous avez une fonction séparée pour dessiner le joueur, appelez-la ici
    // draw_player(*data->mlx, *data->win, data->player);
}

void move_player_forward(t_cub *data)
{
    double new_x;
    double new_y;

    new_x = data->player->pos.x + data->player->dir.x * MOVE_SPEED;
    new_y = data->player->pos.y + data->player->dir.y * MOVE_SPEED;

    if (data->player->map[(int)new_y][(int)new_x] != '1')
    {
        data->player->pos.x = new_x;
        data->player->pos.y = new_y;

        // Mettre à jour l'affichage après le déplacement
        update_display(data);
    }
    printf("%f\n", data->player->pos.y);
}

void test_macro(t_cub *data)
{
    mlx_context mlx = mlx_init();

    mlx_window_create_info info = { 0 };
    info.title = "Test";
    info.width = 1200;
    info.height = 500;
    data->mlx = &mlx;
    mlx_window win = mlx_new_window(*data->mlx, &info);
	data->win = &win;

	// Passer le joueur à draw_map pour dessiner les rayons
    draw_map(mlx, win, data, data->player);

    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, data);
    mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, data);
    mlx_loop(mlx);
}
