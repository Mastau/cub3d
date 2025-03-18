/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:39 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/18 11:15:15 by thomarna         ###   ########.fr       */
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

t_cub *parsing_data(int fd)
{
	t_cub *data;
	char *line;

	data = malloc(sizeof(t_cub));
	if (!data)
		return (NULL);
	while (1)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	return (data);
}
