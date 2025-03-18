/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:39 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/18 14:39:56 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"
#include "stdio.h"

int	check_prefix(char *line)
{
	while (*line && (*line == ' ' || *line == '\n'))
		line++;
	if (*line == '\0')
		return (1);
	else if (*line == 'N' && *line + 1 == 'O')
		return (1);
	else if (*line == 'S' && *line + 1 == 'O')
		return (1);
	else if (*line == 'W' && *line + 1 == 'E')
		return (1);
	else if (*line == 'E' && *line + 1 == 'A')
		return (1);
	else if (*line == 'F')
		return (1);
	else if (*line == 'C')
		return (1);
	return (0);
}

t_cub	*init_data(void)
{
	t_cub	*data;

	data = malloc(sizeof(t_cub));
	if (!data)
		return (NULL);
	ft_memset(data, 0, sizeof(t_cub));
	data->floor = malloc(sizeof(t_rgb));
	data->ceiling = malloc(sizeof(t_rgb));
	if (!data->ceiling || !data->floor)
	{
		free(data->floor);
		free(data->ceiling);
		free(data);
		return (NULL);
	}
	ft_memset(data->ceiling, -1, sizeof(t_rgb));
	ft_memset(data->floor, -1, sizeof(t_rgb));
	return (data);
}

int	parsing_checker(t_cub *data)
{
	int	res;

	res = 0;
	if (!data->ceiling || !data->floor || data->ea || data->no || !data->so
		|| !data->we)
		res = 0;
	return (res);
}

t_cub	*parsing_data(int fd)
{
	t_cub	*data;
	char	*line;

	line = NULL;
	data = init_data();
	if (!data)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		// Call func 4 parse each line
		line = get_next_line(fd);
	}
	return (data);
}
