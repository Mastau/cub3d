/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:22:08 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/13 16:01:59 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	calculate_map_dimensions(t_cub *data, int *width, int *height)
{
	int	i;
	int	line_length;

	i = 0;
	*width = 0;
	*height = 0;
	while (data->map[i] != NULL)
	{
		line_length = ft_strlen(data->map[i]);
		if (line_length > *width)
			*width = line_length;
		i++;
	}
	*height = i;
}

static void	set_player_direction(t_player *player, char orientation)
{
	if (orientation == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (orientation == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (orientation == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (orientation == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
}

static int	find_player_position(t_player *player, t_cub *data,
int map_width, int map_height)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_height)
	{
		x = 0;
		while (x < map_width)
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
				set_player_direction(player, data->map[y][x]);
				// ! print de debug
				printf("Player found at (%d, %d)\n", x, y);
				return (1);
			}
			x++;
		}
		y++;
	}
	// ! print de debug
	printf("Player not found on the map!\n");
	return (0);
}

void	initialize_player(t_player *player, t_cub *data)
{
	int	map_width;
	int	map_height;

	calculate_map_dimensions(data, &map_width, &map_height);
	player->map = data->map;
	player->map_width = map_width;
	player->map_height = map_height;
	find_player_position(player, data, map_width, map_height);
}
