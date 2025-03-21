/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:28:08 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 18:38:30 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <rendering.h>
#include <utils.h>

mlx_image	get_wall_texture(t_textures *textures, int wall_orientation)
{
	mlx_image	texture;

	if (wall_orientation == 0)
		texture = textures->no;
	else if (wall_orientation == 1)
		texture = textures->ea;
	else if (wall_orientation == 2)
		texture = textures->so;
	else
		texture = textures->we;
	return (texture);
}

static void	draw_ceiling(t_line_data *line_data)
{
	int	y;

	y = 0;
	while (y < line_data->start)
	{
		mlx_pixel_put(line_data->mlx, line_data->win,
			line_data->x, y, line_data->ceiling_color);
		y++;
	}
}

static void	draw_floor(t_line_data *line_data)
{
	int	y;

	y = line_data->end;
	while (y < HEIGHT)
	{
		mlx_pixel_put(line_data->mlx, line_data->win,
			line_data->x, y, line_data->floor_color);
		y++;
	}
}

static void	draw_wall(t_line_data *line_data)
{
	int			y;
	mlx_color	texture_color;

	y = line_data->start;
	while (y < line_data->end)
	{
		line_data->tex_y = (int)line_data->tex_pos
			& (line_data->textures->height - 1);
		line_data->tex_pos += line_data->step;
		texture_color = mlx_get_image_pixel(line_data->mlx,
				line_data->current_texture,
				line_data->tex_x, line_data->tex_y);
		mlx_pixel_put(line_data->mlx, line_data->win,
			line_data->x, y, texture_color);
		y++;
	}
}

void	draw_vertical_line(t_render_params *params)
{
	t_line_data	line_data;

	line_data.mlx = params->mlx;
	line_data.win = params->win;
	line_data.x = params->x;
	line_data.wall_height = params->wall_height;
	line_data.textures = params->textures;
	line_data.wall_x = params->wall_x;
	line_data.wall_orientation = params->wall_orientation;
	line_data.data = params->data;
	init_colors(&line_data);
	init_line_data_part1(&line_data);
	init_line_data_part2(&line_data);
	init_line_data_part3(&line_data);
	draw_ceiling(&line_data);
	draw_wall(&line_data);
	draw_floor(&line_data);
}
