/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:06:07 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 18:30:12 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <rendering.h>
#include <utils.h>

void	init_line_data_part1(t_line_data *line_data)
{
	line_data->tex_x = (int)(line_data->wall_x * line_data->textures->width);
	if (line_data->tex_x < 0)
		line_data->tex_x = 0;
	if (line_data->tex_x >= line_data->textures->width)
		line_data->tex_x = line_data->textures->width - 1;
}

void	init_line_data_part2(t_line_data *line_data)
{
	line_data->start = (HEIGHT - line_data->wall_height) / 2;
	if (line_data->start < 0)
		line_data->start = 0;
	line_data->end = line_data->start + line_data->wall_height;
	if (line_data->end > HEIGHT)
		line_data->end = HEIGHT;
}

void	init_line_data_part3(t_line_data *line_data)
{
	line_data->step = (double)line_data->textures->height
		/ line_data->wall_height;
	line_data->tex_pos = (line_data->start
			- (HEIGHT - line_data->wall_height) / 2) * line_data->step;
	line_data->current_texture
		= get_wall_texture(line_data->textures, line_data->wall_orientation);
}

void	init_colors(t_line_data *line_data)
{
	line_data->ceiling_color.rgba
		= convert_rgb_str_to_color(line_data->data->ceiling);
	line_data->floor_color.rgba
		= convert_rgb_str_to_color(line_data->data->floor);
}
