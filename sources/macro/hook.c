/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:02:32 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/17 11:34:55 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

void key_press_hook(int key, void *param)
{
    t_cub *data;

    data = (t_cub *)param;

    if (key == 41)  // Touche Echap
        mlx_loop_end(*data->mlx);
    else if (key == 26)  // W
        data->keys.w = 1;
    else if (key == 22)  // S
        data->keys.s = 1;
    else if (key == 4)   // A
        data->keys.a = 1;
    else if (key == 7)   // D
        data->keys.d = 1;
    else if (key == 80)  // Flèche gauche
        data->keys.left = 1;
    else if (key == 79)  // Flèche droite
        data->keys.right = 1;
}

void key_release_hook(int key, void *param)
{
    t_cub *data;

    data = (t_cub *)param;

    if (key == 26)      // W
        data->keys.w = 0;
    else if (key == 22) // S
        data->keys.s = 0;
    else if (key == 4)  // A
        data->keys.a = 0;
    else if (key == 7)  // D
        data->keys.d = 0;
    else if (key == 80) // Flèche gauche
        data->keys.left = 0;
    else if (key == 79) // Flèche droite
        data->keys.right = 0;
}

void update_game(void *param)
{
    t_cub *data;

    data = (t_cub *)param;

    // Traitement des actions en fonction des touches pressées
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

    // Mise à jour de l'affichage uniquement si une touche est pressée
    if (data->keys.w || data->keys.s || data->keys.a || data->keys.d ||
        data->keys.left || data->keys.right)
        update_display(data);

    // Pas besoin de return puisque la fonction est void
}
