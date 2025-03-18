/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:10:47 by thomarna          #+#    #+#             */
/*   Updated: 2025/03/12 09:45:08 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>
#include "fcntl.h"
#include "libft.h"

int main(int ac, char **av)
{
	int	fd;
	t_cub *data;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Can't open file\n", 2);
		return (1);
	}
	data = parsing_data(fd);
	close(fd);
	if (!data)
		return(1);
	free(data);
}
