/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:34:21 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/18 13:21:07 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_cub
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	*floor;
	t_rgb	*ceiling;
}			t_cub;

typedef struct s_mlx
{
	void	*con;
	void	*win;
}			t_mlx;

t_cub		*parsing_data(int fd);

#endif
