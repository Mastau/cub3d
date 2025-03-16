/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:02:32 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 20:34:43 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

void key_hook(int key, void *param)
{
	t_cub *data;

	data = (t_cub *)param;

	printf("Touche appuyée : %d\n", key);

	if (key == 41)
		mlx_loop_end((mlx_context)param);
	else if (key == 26) // Avancer
		move_player_forward(data);
	else if (key == 22) // Reculer
		move_player_backward(data);
	else if (key == 4) // Gauche
		move_player_left(data);
	else if (key == 7) // Droite
		move_player_right(data);
	else if (key == 80) // Tourner à gauche
		rotate_player_left(data);
	else if (key == 79) // Tourner à droite
		rotate_player_right(data);
}
