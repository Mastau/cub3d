/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:07:41 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 14:26:24 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <macro.h>
#include <raycast.h>
#include <math.h>
#include <minimap.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WALL_HEIGHT 500

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
    info->title = "Cub3D";
    info->width = WINDOW_WIDTH;
    info->height = WINDOW_HEIGHT;
}

static void	window_hook_3d(int event, void *param)
{
    t_cub	*data;

    data = (t_cub *)param;
    if (event == 0)
        mlx_loop_end(*data->mlx);
}

static void	key_press_hook_3d(int key, void *param)
{
    t_cub	*data;

    data = (t_cub *)param;
    if (key == 41)
        mlx_loop_end(*data->mlx);
}

static void	draw_vertical_line(mlx_context mlx, mlx_window win,
                                int x, int wall_height, int color_value)
{
    int			start;
    int			end;
    int			y;
    mlx_color	ceiling_color;
    mlx_color	floor_color;
    mlx_color	wall_color;

    ceiling_color.rgba = 0x333333FF;  // Couleur du plafond
    floor_color.rgba = 0x555555FF;    // Couleur du sol
    wall_color.rgba = color_value;    // Couleur du mur

    start = (WINDOW_HEIGHT - wall_height) / 2;
    end = start + wall_height;

    // Dessiner le plafond
    y = 0;
    while (y < start)
    {
        mlx_pixel_put(mlx, win, x, y, ceiling_color);
        y++;
    }

    // Dessiner le mur
    y = start;
    while (y < end && y < WINDOW_HEIGHT)
    {
        mlx_pixel_put(mlx, win, x, y, wall_color);
        y++;
    }

    // Dessiner le sol
    y = end;
    while (y < WINDOW_HEIGHT)
    {
        mlx_pixel_put(mlx, win, x, y, floor_color);
        y++;
    }
}

static void	render_3d_view(mlx_context mlx, mlx_window win, t_cub *data)
{
    int			i;
    double		angle;
    double		base_angle;
    t_vector	intersection;
    int			hit;
    double		distance;
    int			wall_height;
    int			nb_rayons;
    int			color;

    base_angle = get_base_angle(get_player_orientation(data));
    nb_rayons = WINDOW_WIDTH;

    i = 0;
    while (i < nb_rayons)
    {
        angle = base_angle - (FOV / 2.0) + (i * FOV / (nb_rayons - 1));

        // Normaliser l'angle
        while (angle < 0)
            angle += 360.0;
        while (angle >= 360.0)
            angle -= 360.0;

        // Calculer l'intersection avec le rayon
        ray_cast(data->player, angle, &hit, &intersection);

        if (hit)
        {
            // Calculer la distance (éviter l'effet fisheye)
            distance = sqrt(pow(data->player->pos.x - intersection.x, 2) +
                        pow(data->player->pos.y - intersection.y, 2));
            distance = distance * cos((angle - base_angle) * M_PI / 180.0);

            // Calculer la hauteur du mur (inversement proportionnelle à la distance)
            wall_height = (int)(WALL_HEIGHT / distance);

            // Couleur du mur basée sur la direction (N/S/E/W)
            if (fabs(intersection.x - round(intersection.x)) < 0.01)
                color = 0xFF0000FF; // Rouge pour les murs Est/Ouest
            else
                color = 0x00FF00FF; // Vert pour les murs Nord/Sud

            // Dessiner la ligne verticale représentant une tranche du mur
            draw_vertical_line(mlx, win, i, wall_height, color);
        }
        i++;
    }
}

void	init_3d_rendering(t_cub *data)
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

    // Rendu 3D initial (statique)
    render_3d_view(mlx, win, data);

    // Installation des hooks pour les événements
    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook_3d, data);
    mlx_on_event(mlx, win, MLX_KEYDOWN, key_press_hook_3d, data);

    // Démarrer la boucle principale
    mlx_loop(mlx);
}
