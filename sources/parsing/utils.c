/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:07:22 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/26 15:27:54 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	char_start_checker(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	start_checker(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		if (char_start_checker(str[i], "NSWE"))
			count++;
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	map_error(void)
{
	ft_putstr_fd("Error: Bad element in map\n", 2);
	return (1);
}

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
