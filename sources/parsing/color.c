/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:57:15 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/26 15:40:36 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

char	*assign_color(int r, int g, int b)
{
	char	*tmp;

	tmp = ft_strjoin(ft_itoa(r), ",");
	tmp = ft_strjoin(tmp, ft_itoa(g));
	tmp = ft_strjoin(tmp, ",");
	tmp = ft_strjoin(tmp, ft_itoa(b));
	return (tmp);
}

static int	parse_rgb(char **line, int *color)
{
	if (!ft_isdigit(**line))
		return (-1);
	*color = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	*line = skip_spaces(*line);
	return (0);
}

static int	validate_and_extract_colors(char *line, int *r, int *g, int *b)
{
	if (parse_rgb(&line, r) == -1 || *line != ',')
		return (-1);
	line = skip_spaces(line + 1);
	if (parse_rgb(&line, g) == -1 || *line != ',')
		return (-1);
	line = skip_spaces(line + 1);
	if (parse_rgb(&line, b) == -1)
		return (-1);
	line = skip_spaces(line);
	if (*line != '\0' && *line != '\n')
		return (-1);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
		return (-1);
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
	line = skip_spaces(line + 1);
	if (validate_and_extract_colors(line, &r, &g, &b) == -1)
		return (-1);
	if (type == 'F')
		data->floor = assign_color(r, g, b);
	else
		data->ceiling = assign_color(r, g, b);
	return (0);
}
