/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:18:54 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/26 13:39:45 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_param(int ac, char **av)
{
	int		len;
	char	*ext;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (1);
	}
	len = ft_strlen(av[1]);
	if (len < 5)
	{
		ft_putstr_fd("Error: Use a .cub file\n", 2);
		return (1);
	}
	ext = ft_substr(av[1], len - 4, 4);
	if (ft_strncmp(ext, ".cub", 4))
	{
		ft_putstr_fd("Error: Use a .cub file\n", 2);
		return (1);
	}
	return (0);
}
