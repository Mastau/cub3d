/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:39:28 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 15:07:37 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <cub.h>

typedef struct s_ray_params
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
}	t_ray_params;

typedef struct s_ray_info
{
	t_player		*player;
	t_vector		*intersection;
	double			ray_dir_x;
	double			ray_dir_y;
	t_ray_params	*params;
}	t_ray_info;

void	init_ray_steps(t_player *player, double ray_dir_x, double ray_dir_y,
			t_ray_params *params);
void	calculate_intersection(t_ray_info *ray_info, int side);

#endif
