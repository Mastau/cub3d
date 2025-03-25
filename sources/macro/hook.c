/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:02:32 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/21 14:14:32 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <macro.h>

void	window_hook(int event, void *param)
{
	t_cub	*data;

	data = (t_cub *)param;
	if (event == 0)
		mlx_loop_end(*data->mlx);
}

void	key_press_hook(int key, void *param)
{
	t_cub	*data;

	data = (t_cub *)param;
	if (key == 41)
		mlx_loop_end(*data->mlx);
	else if (key == 26)
		data->keys.w = 1;
	else if (key == 22)
		data->keys.s = 1;
	else if (key == 4)
		data->keys.a = 1;
	else if (key == 7)
		data->keys.d = 1;
	else if (key == 80)
		data->keys.left = 1;
	else if (key == 79)
		data->keys.right = 1;
	else if (key == 225)
		data->keys.sprint = 1;
}

void	key_release_hook(int key, void *param)
{
	t_cub	*data;

	data = (t_cub *)param;
	if (key == 26)
		data->keys.w = 0;
	else if (key == 22)
		data->keys.s = 0;
	else if (key == 4)
		data->keys.a = 0;
	else if (key == 7)
		data->keys.d = 0;
	else if (key == 80)
		data->keys.left = 0;
	else if (key == 79)
		data->keys.right = 0;
	else if (key == 225)
		data->keys.sprint = 0;
}
