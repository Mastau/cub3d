/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:46:47 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 19:41:11 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <cub.h>

typedef struct s_ray_params
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	color;
}	t_ray_params;

typedef struct s_square_params
{
	int	x;
	int	y;
	int	color;
}	t_square_params;

void	draw_map_row(mlx_context mlx, mlx_window win, t_cub *data, int y);
void	draw_map(mlx_context mlx, mlx_window win, t_cub *data,
			t_player *player);
void	draw_map_tile(mlx_context mlx, mlx_window win, t_cub *data,
			int coords[2]);
void	draw_map_tiles(mlx_context mlx, mlx_window win, t_cub *data);
char	get_player_orientation(t_cub *data);
double	get_base_angle(char orientation);
void	cast_and_draw_rays(mlx_context mlx, mlx_window win,
			t_player *player, double base_angle);
void	draw_ray(mlx_context mlx, mlx_window win, t_ray_params *params);
void	draw_square(mlx_context mlx, mlx_window win, t_square_params *params);
void	draw_player(mlx_context mlx, mlx_window win,
			t_player *player);

#endif
