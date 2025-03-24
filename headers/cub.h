/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:34:21 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/24 13:10:31 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include <stdio.h>

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
	char	*map_line;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	*floor;
	t_rgb	*ceiling;
}			t_cub;

typedef struct s_param
{
	int		i;
	int		height;
	int		prev_len;
}			t_param;

typedef struct s_mlx
{
	void	*con;
	void	*win;
}			t_mlx;

t_cub		*parsing_data(int fd);
char		*skip_spaces(char *str);
int			check_prefix(char *line);
int			parsing_color(t_cub *data, char *line);
int			parsing_path(t_cub *data, char *line);

t_cub		*parsing_map(t_cub *data, char *line, int fd);
int			char_start_checker(char c, char *charset);
int			start_checker(char *str);
int			map_fill(t_cub *data);
int			map_error(void);
int			check_cell(char **map, int j, int curr_len, t_param *param);
#endif
