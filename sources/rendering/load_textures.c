/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:22:09 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 17:22:36 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <rendering.h>

t_textures load_textures(mlx_context mlx, t_cub *data)
{
    t_textures textures;
	int img_width;
	int img_height;

	textures.no = mlx_new_image_from_file(mlx, data->no, &img_width,
	&img_height);
    textures.so = mlx_new_image_from_file(mlx, data->so, &img_width,
	&img_height);
    textures.we = mlx_new_image_from_file(mlx, data->we, &img_width,
	&img_height);
    textures.ea = mlx_new_image_from_file(mlx, data->ea, &img_width,
	&img_height);
    textures.width = img_width;
    textures.height = img_height;
    return (textures);
}
