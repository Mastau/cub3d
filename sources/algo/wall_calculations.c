/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:12:55 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 13:15:43 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <raycast.h>

int	calculate_wall_height(double distance_perp)
{
    if (distance_perp <= 0.01)
        distance_perp = 0.01;
    return ((int)(HEIGHT / distance_perp));
}

double	calculate_perp_distance(t_player *player, double ray_dir_x,
	double ray_dir_y, int side, int map_x, int map_y)
{
	double	perp_wall_dist;

	if (side == 0)
	perp_wall_dist = (map_x - player->pos.x + (1 - (int)ray_dir_x) / 2)
	/ ray_dir_x;
	else
	perp_wall_dist = (map_y - player->pos.y + (1 - (int)ray_dir_y) / 2)
	/ ray_dir_y;
	return (perp_wall_dist);
}

int	calculate_texture_x(t_vector intersection, int side, int texture_width)
{
    double	wall_x;
    int		tex_x;

    if (side == 0)
        wall_x = intersection.y - floor(intersection.y);
    else
        wall_x = intersection.x - floor(intersection.x);

    tex_x = (int)(wall_x * texture_width);
    if ((side == 0 && intersection.x > 0) || (side == 1 && intersection.y < 0))
        tex_x = texture_width - tex_x - 1;

    return (tex_x);
}

char	*get_wall_texture(double ray_dir_x, double ray_dir_y,
	int side, t_cub *cub)
{
	if (side == 0)
	{
	if (ray_dir_x > 0)
		return (cub->we); // Mur Ouest
	else
		return (cub->ea); // Mur Est
	}
	else
	{
		if (ray_dir_y > 0)
			return (cub->no); // Mur Nord
		else
			return (cub->so); // Mur Sud
	}
}
