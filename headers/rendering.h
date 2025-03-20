/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:11:54 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 18:42:34 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include <cub.h>
# include <raycast.h>

typedef struct s_textures
{
	mlx_image	no;
	mlx_image	so;
	mlx_image	we;
	mlx_image	ea;
	int			width;
	int			height;
}	t_textures;

typedef struct s_line_data
{
	t_textures	*textures;
	mlx_image	current_texture;
	int			tex_x;
	int			tex_y;
	double		wall_x;
	double		tex_pos;
	double		step;
	int			start;
	int			end;
	int			wall_height;
	int			wall_orientation;
	mlx_color	ceiling_color;
	mlx_color	floor_color;
	mlx_context	mlx;
	mlx_window	win;
	int			x;
	t_cub		*data;
}	t_line_data;

typedef struct s_render_params
{
	mlx_context	mlx;
	mlx_window	win;
	int			x;
	int			wall_height;
	t_textures	*textures;
	double		wall_x;
	int			wall_orientation;
	t_cub		*data;
}	t_render_params;

typedef struct s_render_context
{
	mlx_context	mlx;
	mlx_window	win;
	t_cub		*data;
	t_textures	*textures;
	double		base_angle;
}	t_render_context;

void		init_keys(t_cub *data);
void		init_window_info(mlx_window_create_info *info);
t_textures	load_textures(mlx_context mlx, t_cub *data);
void		draw_vertical_line(t_render_params *params);
void		render_3d_view(mlx_context mlx, mlx_window win,
				t_cub *data, t_textures *textures);
void		determine_wall_orientation_part1(t_ray_data *ray, t_player *player);
void		determine_wall_orientation_part2(t_ray_data *ray, double y_diff);
void		determine_wall_orientation_part3(t_ray_data *ray,
				double x_diff, double y_diff);
void		init_ray_data(t_ray_data *ray, double base_angle,
				int i, int nb_rays);
void		init_render_params(t_render_params *params, int i,
				t_ray_data *ray, t_render_context *ctx);
void		init_line_data_part1(t_line_data *line_data);
void		init_line_data_part2(t_line_data *line_data);
void		init_line_data_part3(t_line_data *line_data);
void		init_colors(t_line_data *line_data);
mlx_image	get_wall_texture(t_textures *textures, int wall_orientation);
void		init_3d_rendering(t_cub *data);

#endif
