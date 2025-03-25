/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:07:22 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/24 14:10:55 by thomarna         ###   ########.fr       */
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
	ft_putstr_fd("Error\nBad element in map\n", 2);
	return (1);
}
