/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:39 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/20 13:42:02 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"
#include "stdio.h"

char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	check_prefix(char *line)
{
	line = skip_spaces(line);
	if (*line == '\0' || *line == '\n')
		return (1);
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
		|| *line == 'F' || *line == 'C')
		return (1);
	return (0);
}

int	parsing_color(t_cub *data, char *line)
{
	char	type;
	int		r;
	int		g;
	int		b;

	line = skip_spaces(line);
	type = *line;
	if (type != 'F' && type != 'C')
		return (-1);
	line++;
	line = skip_spaces(line);
	if (!ft_isdigit(*line))
		return (-1);
	r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = skip_spaces(line);
	if (*line != ',')
		return (-1);
	line++;
	line = skip_spaces(line);
	if (!ft_isdigit(*line))
		return (-1);
	g = atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = skip_spaces(line);
	if (*line != ',')
		return (-1);
	line++;
	line = skip_spaces(line);
	if (!ft_isdigit(*line))
		return (-1);
	b = atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = skip_spaces(line);
	if (*line != '\0' && *line != '\n')
		return (-1);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	if (type == 'F')
	{
		printf("F: r%d, g%d, b%d", r, g, b);
		data->floor->r = r;
		data->floor->g = g;
		data->floor->b = b;
	}
	else
	{
		printf("C: r%d, g%d, b%d\n", r, g, b);
		data->ceiling->r = r;
		data->ceiling->g = g;
		data->ceiling->b = b;
	}
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
	printf("Data init\n");
	return (data);
}

int	parsing_checker(t_cub *data)
{
	int	res;

	res = 0;
	if (!data->ceiling || !data->floor || data->ea || data->no || !data->so
		|| !data->we)
		res = 1;
	if (data->floor->r == -1 && data->floor->g == -1 && data->floor->b == -1)
		res = 1;
	if (data->ceiling->r == -1 && data->ceiling->g == -1
		&& data->ceiling->b == -1)
		res = 1;
	return (res);
}

int	parsing_path(t_cub *data, char *line)
{
	(void) data;
	(void) line;
	return (0);
}

int	parsing_line(t_cub *data, char *line)
{
	int	res;

	res = 0;
	if (parsing_checker(data))
	{
		printf("Parsing not complete\n");
		if (!check_prefix(line))
		{
			printf("Prefix detected\n");
			if (parsing_color(data, line) || parsing_path(data, line))
				return (-1);
		}

	}
	return (res);
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
	line = get_next_line(fd);
	while (line)
	{
		res = parsing_line(data, line);
		printf("res:%d\n", res);
		line = get_next_line(fd);
	}
	return (data);
}
