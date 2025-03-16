/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:07:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 19:59:56 by jlorette         ###   ########.fr       */
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
    double rotation_speed = 0.1; // Radians
    double cos_rot = cos(-rotation_speed);
    double sin_rot = sin(-rotation_speed);

    // Appliquer la matrice de rotation
    data->player->dir.x = data->player->dir.x * cos_rot - data->player->dir.y * sin_rot;
    data->player->dir.y = old_dir_x * sin_rot + data->player->dir.y * cos_rot;

    update_display(data);
}

void rotate_player_right(t_cub *data)
{
    // Rotation de la direction du joueur vers la droite
    double old_dir_x = data->player->dir.x;
    double rotation_speed = 0.1; // Radians
    double cos_rot = cos(rotation_speed);
    double sin_rot = sin(rotation_speed);

    // Appliquer la matrice de rotation
    data->player->dir.x = data->player->dir.x * cos_rot - data->player->dir.y * sin_rot;
    data->player->dir.y = old_dir_x * sin_rot + data->player->dir.y * cos_rot;

    update_display(data);
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
        update_display(data);
    }
}

void move_player_left(t_cub *data)
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
        update_display(data);
    }
}

void move_player_right(t_cub *data)
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
        update_display(data);
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
        update_display(data);
    }
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
