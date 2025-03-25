/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:39 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/24 13:43:17 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_cub	*init_data(void)
{
	t_cub	*data;

	data = malloc(sizeof(t_cub));
	if (!data)
		return (NULL);
	ft_memset(data, 0, sizeof(t_cub));
	data->floor = lp_alloc(sizeof(t_rgb));
	data->ceiling = lp_alloc(sizeof(t_rgb));
	if (!data->ceiling || !data->floor)
	{
		free(data->floor);
		free(data->ceiling);
		free(data);
		return (NULL);
	}
	ft_memset(data->ceiling, -1, sizeof(t_rgb));
	ft_memset(data->floor, -1, sizeof(t_rgb));
	printf("Data init\n");
	return (data);
}

int	parsing_checker(t_cub *data)
{
	if (!data->ceiling || !data->floor || !data->ea || !data->no || !data->so
		|| !data->we)
		return (1);
	if (data->floor->r == -1 && data->floor->g == -1 && data->floor->b == -1)
		return (1);
	if (data->ceiling->r == -1 && data->ceiling->g == -1 && data->ceiling->b ==
		-1)
		return (1);
	return (0);
}

int	parsing_line(t_cub *data, char *line)
{
	if (line == NULL)
		return (0);
	printf("Parsing Checker: %d\n", parsing_checker(data));
	if (parsing_checker(data))
	{
		if (check_prefix(line))
		{
			printf("Prefix detected\n");
			if (parsing_color(data, line) == 0 || parsing_path(data, line) == 0)
				return (3);
		}
		else
			return (3);
	}
	else
		return (1);
	return (3);
}

void	*error_parsing(t_cub *data, char *line)
{
	(void)data;
	(void)line;
	ft_putstr_fd("Error: Incorrect elements\n", 2);
	return (NULL);
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
			return (error_parsing(data, line));
		else
			continue ;
	}
	return (data);
}
