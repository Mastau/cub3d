/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:11:14 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 17:13:07 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	init_keys(t_cub *data)
{
    data->keys.w = 0;
    data->keys.s = 0;
    data->keys.a = 0;
    data->keys.d = 0;
    data->keys.left = 0;
    data->keys.right = 0;
}

void	init_window_info(mlx_window_create_info *info)
{
    *info = (mlx_window_create_info){0};
    info->title = "Cub3D";
    info->width = WIDTH;
    info->height = HEIGHT;
}
