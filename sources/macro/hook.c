/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:02:32 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 18:06:17 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

void	key_hook(int key, void *param)
{
	t_cub	*data;

    data = (t_cub *)param;
	if (key == 41)
		mlx_loop_end((mlx_context)param);
	if (key == 26)
	{
		move_player_forward(data);
	}
}
