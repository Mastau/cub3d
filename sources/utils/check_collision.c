/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:13:14 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/25 16:03:52 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	check_collision(t_cub *data, double x, double y, char axis)
{
	if (axis == 'x')
		return (data->player->map[(int)data->player->pos.y][(int)x] == '1');
	return (data->player->map[(int)y][(int)data->player->pos.x] == '1');
}
