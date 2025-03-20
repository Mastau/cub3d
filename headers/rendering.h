/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:11:54 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 17:23:58 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include <cub.h>

typedef struct s_textures
{
    mlx_image   no;
    mlx_image   so;
    mlx_image   we;
    mlx_image   ea;
    int         width;
    int         height;
} t_textures;

void		init_keys(t_cub *data);
void		init_window_info(mlx_window_create_info *info);
t_textures	load_textures(mlx_context mlx, t_cub *data);

#endif
