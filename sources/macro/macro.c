/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:07:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/17 12:03:56 by jlorette         ###   ########.fr       */
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

}
void rotate_player_left(t_cub *data)
{
    // Rotation de la direction du joueur vers la gauche
    double old_dir_x = data->player->dir.x;
    double cos_rot = cos(-ROTATION_SPEED);
    double sin_rot = sin(-ROTATION_SPEED);

    // Appliquer la matrice de rotation
    data->player->dir.x = data->player->dir.x * cos_rot - data->player->dir.y * sin_rot;
    data->player->dir.y = old_dir_x * sin_rot + data->player->dir.y * cos_rot;
}

void rotate_player_right(t_cub *data)
{
    // Rotation de la direction du joueur vers la droite
    double old_dir_x = data->player->dir.x;
    double cos_rot = cos(ROTATION_SPEED);
    double sin_rot = sin(ROTATION_SPEED);

    // Appliquer la matrice de rotation
    data->player->dir.x = data->player->dir.x * cos_rot - data->player->dir.y * sin_rot;
    data->player->dir.y = old_dir_x * sin_rot + data->player->dir.y * cos_rot;
}

void move_player_backward(t_cub *data)
{
    double new_x;
    double new_y;

    // Mouvement dans la direction opposée
    new_x = data->player->pos.x - data->player->dir.x * MOVE_SPEED;
    new_y = data->player->pos.y - data->player->dir.y * MOVE_SPEED;

    if (data->player->map[(int)new_y][(int)new_x] != '1')
    {
        data->player->pos.x = new_x;
        data->player->pos.y = new_y;
    }
}

void move_player_right(t_cub *data)
{
    double new_x;
    double new_y;

    // Mouvement perpendiculaire à la direction (à gauche)
    new_x = data->player->pos.x - data->player->dir.y * MOVE_SPEED;
    new_y = data->player->pos.y + data->player->dir.x * MOVE_SPEED;

    if (data->player->map[(int)new_y][(int)new_x] != '1')
    {
        data->player->pos.x = new_x;
        data->player->pos.y = new_y;
    }
}

void move_player_left(t_cub *data)
{
    double new_x;
    double new_y;

    // Mouvement perpendiculaire à la direction (à droite)
    new_x = data->player->pos.x + data->player->dir.y * MOVE_SPEED;
    new_y = data->player->pos.y - data->player->dir.x * MOVE_SPEED;

    if (data->player->map[(int)new_y][(int)new_x] != '1')
    {
        data->player->pos.x = new_x;
        data->player->pos.y = new_y;
    }
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
    }
}



void test_macro(t_cub *data)
{
    mlx_context mlx = mlx_init();

    // Initialisation des touches
    data->keys.w = 0;
    data->keys.s = 0;
    data->keys.a = 0;
    data->keys.d = 0;
    data->keys.left = 0;
    data->keys.right = 0;


    mlx_window_create_info info = { 0 };
    info.title = "Test";
    info.width = 1200;
    info.height = 500;
    data->mlx = &mlx;
    mlx_window win = mlx_new_window(*data->mlx, &info);
    data->win = &win;
    draw_map(mlx, win, data, data->player);

    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, data);
    mlx_on_event(mlx, win, MLX_KEYDOWN, key_press_hook, data);
    mlx_on_event(mlx, win, MLX_KEYUP, key_release_hook, data);
    mlx_add_loop_hook(mlx, update_game, data);
    mlx_loop(mlx);
}
