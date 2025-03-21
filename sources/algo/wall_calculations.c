/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:12:55 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 18:18:58 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <raycast.h>

char	*get_wall_texture(double ray_dir_x, double ray_dir_y,
	int side, t_cub *cub)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (cub->we);
		else
			return (cub->ea);
	}
	else
	{
		if (ray_dir_y > 0)
			return (cub->no);
		else
			return (cub->so);
	}
}
