/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:34:21 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/25 16:36:29 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <math.h>
# include <libft.h>
# include <mlx.h>

# define M_PI 3.14159265358979323846
# define WIDTH 1042
# define HEIGHT 720
# define FOV 40
# define MOVE_SPEED 0.06
# define ROTATION_SPEED 0.06
# define WALL_HEIGHT 800
# define WALL_MARGIN 0.3

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_param
{
	int		i;
	int		height;
	int		prev_len;
}			t_param;

typedef struct s_textures
{
	mlx_image	no;
	mlx_image	so;
	mlx_image	we;
	mlx_image	ea;
	int			width;
	int			height;
}	t_textures;

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
	int	sprint;
}	t_keys;

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

typedef struct s_cub
{
	char		**map;
	char		*map_line;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*floor;
	char		*ceiling;
	t_rgb		*floor_color;
	t_rgb		*ceiling_color;
	mlx_context	*mlx;
	mlx_window	*win;
	t_player	*player;
	t_keys		keys;
	t_textures	*textures;

}	t_cub;

void	initialize_player(t_player *player, t_cub *data);
void	ray_cast(t_player *player, double angle, int *hit,
			t_vector *intersection);
double	degree_to_radian(double degree);
void	window_hook(int event, void *param);
void	draw_map(mlx_context mlx, mlx_window win,
			t_cub *data, t_player *player);

t_cub	*parsing_map(t_cub *data, char *line, int fd);
int		char_start_checker(char c, char *charset);
int		start_checker(char *str);
int		map_fill(t_cub *data);
int		map_error(void);
int		check_cell(char **map, int j, int curr_len, t_param *param);

t_cub	*parsing_data(int fd);
char	*skip_spaces(char *str);
int		check_prefix(char *line);
int		parsing_color(t_cub *data, char *line);
int		parsing_path(t_cub *data, char *line);

#endif
