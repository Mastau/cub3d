/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:34:21 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/17 15:36:19 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <math.h>
# include <libft.h>
# include <mlx.h>

# define M_PI 3.14159265358979323846
# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.03

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	char		orientation;
	char		**map;
	int			map_width;
	int			map_height;
}	t_player;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_cub
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*floor;
	char		*ceiling;
	mlx_context	*mlx;
	mlx_window	*win;
	t_player	*player;
	t_keys		keys;

}	t_cub;

typedef struct s_mlx
{
	void	*con;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_intersection_data
{
	t_vector	*intersection;
	t_player	*player;
	double		ray_dir_x;
	double		ray_dir_y;
	double		dist;
}	t_intersection_data;

void	initialize_player(t_player *player, t_cub *data);
void	ray_cast(t_player *player, double angle, int *hit,
			t_vector *intersection);
double	degree_to_radian(double degree);
void	window_hook(int event, void *param);
void	draw_map(mlx_context mlx, mlx_window win,
			t_cub *data, t_player *player);

#endif
