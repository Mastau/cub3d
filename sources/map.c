/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:39 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/21 17:40:02 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_cub *parsing_map(t_cub *data, char *line, int fd)
{
	char *tmp;

	data->map_line = ft_strdup(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strjoin(data->map_line, line);
		free(line);
		free(data->map_line);
		data->map_line = ft_strdup(tmp);
		if (ft_strlen(data->map_line) > 25000)
		{
			ft_putstr_fd("Error: Map too large\n", 2);
			free(tmp);
			return (NULL);
		}
		free(tmp);
	}
	return (data);
}
