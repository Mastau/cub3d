/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:57:15 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/25 13:19:54 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	check_prefix(char *line)
{
	while (*line && (*line == ' ' || *line == '\n'))
		line++;
	if (*line == '\0')
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
		printf("F: r%d, g%d, b%d\n", r, g, b);
		data->floor_color->r = r;
		data->floor_color->g = g;
		data->floor_color->b = b;
	}
	else
	{
		printf("C: r%d, g%d, b%d\n", r, g, b);
		data->ceiling_color->r = r;
		data->ceiling_color->g = g;
		data->ceiling_color->b = b;
	}
	return (0);
}

