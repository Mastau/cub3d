/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:20:46 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/21 16:01:31 by thomarna         ###   ########.fr       */
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
	printf("%s\n", line);
	return (ft_strdup(line));
}

static char	*parsing_path_step2(t_cub *data, char *line)
{
	char	*path;
	if (ft_strncmp(line, "WE", 2) == 0)
	{
		path = extract_path(line + 2);
		data->we = path;
		printf("WE: %s\n", path);
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		path = extract_path(line + 2);
		data->ea = path;
		printf("EA: %s\n", path);
	}
	else
		return (NULL);
	return (path);
}

int	parsing_path(t_cub *data, char *line)
{
	char	*path;
	printf("oui\n");
	line = skip_spaces(line);
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		path = extract_path(line + 2);
		data->no = path;
		printf("NO: %s\n", path);
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		path = extract_path(line + 2);
		data->so = path;
		printf("SO: %s\n", path);
	}
	else if (ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		path = parsing_path_step2(data, line);
	else
		return (-1);
	if (!path)
		return (-1);
	return (0);
}
