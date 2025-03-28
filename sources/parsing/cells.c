/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:02:18 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/24 13:03:10 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_cell_left(char **map, int i, int j)
{
	if (j == 0 || map[i][j - 1] == ' ')
		return (0);
	return (1);
}

static int	check_cell_right(char **map, int i, int j, int len)
{
	if (j == len - 1 || map[i][j + 1] == ' ')
		return (0);
	return (1);
}

static int	check_cell_up(char **map, int i, int j, int prev_len)
{
	if (i > 0)
	{
		if (j >= prev_len || map[i - 1][j] == ' ')
			return (0);
	}
	return (1);
}

static int	check_cell_down(char **map, int i, int j, int height)
{
	int	next_len;

	if (i < height - 1)
	{
		next_len = ft_strlen(map[i + 1]);
		if (j >= next_len || map[i + 1][j] == ' ')
			return (0);
	}
	return (1);
}

int	check_cell(char **map, int j, int curr_len, t_param *param)
{
	if ((param->i == 0 || param->i == param->height - 1)
		&& (map[param->i][j] == '0' || ft_strchr("NSEW", map[param->i][j])))
		return (0);
	if (map[param->i][j] != '0' && map[param->i][j] != 'N'
		&& map[param->i][j] != 'S' && map[param->i][j] != 'W'
		&& map[param->i][j] != 'E')
		return (1);
	if (!check_cell_left(map, param->i, j))
		return (0);
	if (!check_cell_right(map, param->i, j, curr_len))
		return (0);
	if (!check_cell_up(map, param->i, j, param->prev_len))
		return (0);
	if (!check_cell_down(map, param->i, j, param->height))
		return (0);
	return (1);
}
