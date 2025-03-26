/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:22:09 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/25 14:30:24 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <rendering.h>

static void	texture_error_exit(mlx_context mlx, char *texture_path,
								t_textures *loaded)
{
	ft_putstr_fd("Error: Failed to load texture: ", 2);
	ft_putstr_fd(texture_path, 2);
	ft_putstr_fd("\n", 2);
	if (loaded->no)
		mlx_destroy_image(mlx, loaded->no);
	if (loaded->so)
		mlx_destroy_image(mlx, loaded->so);
	if (loaded->we)
		mlx_destroy_image(mlx, loaded->we);
	if (loaded->ea)
		mlx_destroy_image(mlx, loaded->ea);
	exit(EXIT_FAILURE);
}

static t_textures	init_textures(void)
{
	t_textures	textures;

	textures.no = NULL;
	textures.so = NULL;
	textures.we = NULL;
	textures.ea = NULL;
	textures.width = 0;
	textures.height = 0;
	return (textures);
}

t_textures	load_textures(mlx_context mlx, t_cub *data)
{
	t_textures	textures;
	int			img_width;
	int			img_height;

	textures = init_textures();
	textures.no = mlx_new_image_from_file(mlx, data->no, &img_width,
			&img_height);
	if (!textures.no)
		texture_error_exit(mlx, data->no, &textures);
	textures.so = mlx_new_image_from_file(mlx, data->so, &img_width,
			&img_height);
	if (!textures.so)
		texture_error_exit(mlx, data->so, &textures);
	textures.we = mlx_new_image_from_file(mlx, data->we, &img_width,
			&img_height);
	if (!textures.we)
		texture_error_exit(mlx, data->we, &textures);
	textures.ea = mlx_new_image_from_file(mlx, data->ea, &img_width,
			&img_height);
	if (!textures.ea)
		texture_error_exit(mlx, data->ea, &textures);
	textures.width = img_width;
	textures.height = img_height;
	return (textures);
}
