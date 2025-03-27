/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:39 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/27 17:23:17 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_cub	*init_data(void)
{
	t_cub	*data;

	data = lp_alloc(sizeof(t_cub));
	if (!data)
		return (NULL);
	ft_memset(data, 0, sizeof(t_cub));
	data->floor_color = lp_alloc(sizeof(t_rgb));
	data->ceiling_color = lp_alloc(sizeof(t_rgb));
	if (!data->ceiling_color || !data->floor_color)
		return (NULL);
	ft_memset(data->ceiling_color, -1, sizeof(t_rgb));
	ft_memset(data->floor_color, -1, sizeof(t_rgb));
	return (data);
}

int	parsing_checker(t_cub *data)
{
	if (!data->ceiling || !data->floor || !data->ea || !data->no || !data->so
		|| !data->we)
		return (1);
	return (0);
}

int	parsing_prefix_elements(t_cub *data, char *line)
{
	int	result;

	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		result = parsing_color(data, line);
		if (result == -1)
			return (2);
		return (3);
	}
	else
	{
		result = parsing_path(data, line);
		if (result == -1)
			return (2);
		return (3);
	}
}

int	parsing_line(t_cub *data, char *line)
{
	if (line == NULL)
		return (0);
	if (parsing_checker(data))
	{
		if (check_prefix(line))
			return (parsing_prefix_elements(data, line));
		else
			return (2);
	}
	else
		return (1);
	return (3);
}

t_cub	*parsing_data(int fd)
{
	t_cub	*data;
	char	*line;
	int		res;

	line = NULL;
	data = init_data();
	if (!data)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		res = parsing_line(data, line);
		if (res == 0)
			break ;
		else if (res == 1)
		{
			data = parsing_map(data, line, fd);
			break ;
		}
		else if (res == 2)
			return (error_parsing());
		else
			continue ;
	}
	return (data);
}
