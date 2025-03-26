/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:20:46 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/26 13:41:08 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

static char	*extract_path(char *line)
{
	line = skip_spaces(line);
	if (*line == '\0' || *line == '\n')
		return (NULL);
	line = ft_strtrim(line, "\n \t");
	return (ft_strdup(line));
}

static char	*parsing_path_step2(t_cub *data, char *line)
{
	char	*path;

	if (ft_strncmp(line, "WE", 2) == 0)
	{
		path = extract_path(line + 2);
		data->we = path;
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		path = extract_path(line + 2);
		data->ea = path;
	}
	else
		return (NULL);
	return (path);
}

int	parsing_path(t_cub *data, char *line)
{
	char	*path;

	line = skip_spaces(line);
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		path = extract_path(line + 2);
		data->no = path;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		path = extract_path(line + 2);
		data->so = path;
	}
	else if (ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		path = parsing_path_step2(data, line);
	else
		return (-1);
	if (!path)
		return (-1);
	return (0);
}
