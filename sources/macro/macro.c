/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:07:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/14 16:06:54 by jlorette         ###   ########.fr       */
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

void draw_map(mlx_context mlx, mlx_window win, t_cub *data, t_player *player)
{
    int taille_carre = 30;
    int y_offset = 50;
    int x_offset = 50;

    // Dessiner la map
    for (int y = 0; data->map[y] != NULL; y++) {
        for (int x = 0; data->map[y][x] != '\0'; x++) {
            int pos_x = x_offset + x * taille_carre;
            int pos_y = y_offset + y * taille_carre;

            if (data->map[y][x] == '1') {
                for (int dy = 0; dy < taille_carre; dy++) {
                    for (int dx = 0; dx < taille_carre; dx++) {
                        mlx_pixel_put(mlx, win, pos_x + dx, pos_y + dy, (mlx_color){ .rgba = 0xFFFFFFFF });
                    }
                }
            } else if (data->map[y][x] == 'N' || data->map[y][x] == 'S' ||
                       data->map[y][x] == 'E' || data->map[y][x] == 'W') {
                for (int dy = 0; dy < taille_carre; dy++) {
                    for (int dx = 0; dx < taille_carre; dx++) {
                        mlx_pixel_put(mlx, win, pos_x + dx, pos_y + dy, (mlx_color){ .rgba = 0xFF0000FF });
                    }
                }
            }
        }
    }

    // Dessiner les rayons (on en réduit le nombre)
    if (player) {
        // Position du joueur sur la carte (en pixels)
        int player_x = x_offset + (int)(player->pos.x * taille_carre);
        int player_y = y_offset + (int)(player->pos.y * taille_carre);

        // Nombre de rayons pour faire un tour complet (360°)
        int nb_rayons = 70; // Vous pouvez ajuster ce nombre pour avoir plus de rayons

        // Angle de départ (0° = direction est)
        double angle_start = 0;
        // Incrément d'angle pour couvrir les 360°
        double angle_step = 360.0 / nb_rayons;

        for (int i = 0; i < nb_rayons; i++) {
            // Calculer l'angle du rayon (en degrés)
            double angle = angle_start + i * angle_step;

            // Variables pour stocker le résultat du ray casting
            int hit = 0;
            t_vector intersection;

            // Lancer le rayon
            ray_cast(player, angle, &hit, &intersection);

            if (hit) {
                // Convertir les coordonnées d'intersection en pixels
                int ray_end_x = x_offset + (int)(intersection.x * taille_carre);
                int ray_end_y = y_offset + (int)(intersection.y * taille_carre);

                // Le reste du code pour tracer la ligne reste inchangé
                // Algorithme de Bresenham pour tracer une ligne
                int dx = abs(ray_end_x - player_x);
                int sx = player_x < ray_end_x ? 1 : -1;
                int dy = -abs(ray_end_y - player_y);
                int sy = player_y < ray_end_y ? 1 : -1;
                int err = dx + dy;
                int e2;

                int x = player_x;
                int y = player_y;

                while (1) {
                    // Dessiner le pixel du rayon en jaune
                    mlx_pixel_put(mlx, win, x, y, (mlx_color){ .rgba = 0xFFFF00FF });

                    if (x == ray_end_x && y == ray_end_y)
                        break;

                    e2 = 2 * err;
                    if (e2 >= dy) {
                        if (x == ray_end_x)
                            break;
                        err += dy;
                        x += sx;
                    }
                    if (e2 <= dx) {
                        if (y == ray_end_y)
                            break;
                        err += dx;
                        y += sy;
                    }
                }
            }
        }
    }
}

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
