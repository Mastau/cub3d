/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:39 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/28 09:16:11 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_cub	*parsing_map(t_cub *data, char *line, int fd)
{
	char	*tmp;

	data->map_line = ft_strdup(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strjoin(data->map_line, line);
		data->map_line = ft_strdup(tmp);
		if (ft_strlen(data->map_line) > 25000)
		{
			ft_putstr_fd("Error: Map too large\n", 2);
			free(tmp);
			return (NULL);
		}
	}
	return (data);
}

static int	line_checker(char **map, t_param *param)
{
	int	j;
	int	curr_len;

	curr_len = ft_strlen(map[param->i]);
	j = 0;
	while (j < curr_len)
	{
		if (!check_cell(map, j, curr_len, param))
			return (0);
		j++;
	}
	return (curr_len);
}

static int	check_map(char **map)
{
	t_param	*param;

	if (!map || !map[0])
		return (0);
	param = lp_alloc(sizeof(t_param));
	if (!param)
		return (0);
	param->height = 0;
	while (map[param->height])
		param->height++;
	param->i = 0;
	param->prev_len = ft_strlen(map[0]);
	while (param->i < param->height)
	{
		param->prev_len = line_checker(map, param);
		if (param->prev_len == 0)
			return (0);
		param->i++;
	}
	return (1);
}

int	map_fill(t_cub *data)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strtrim(data->map_line, "\n");
	if (!tmp)
		return (map_error());
	while (tmp && tmp[i])
	{
		if (!start_checker(tmp))
			return (map_error());
		if (char_start_checker(tmp[i], " \n01NSWE"))
			return (map_error());
		if (tmp[i] == '\n' && tmp[i + 1] == '\n')
			return (map_error());
		i++;
	}
	data->map = ft_split(tmp, '\n');
	if (!data->map)
		return (1);
	if (!check_map(data->map))
		return (map_error());
	return (0);
}
