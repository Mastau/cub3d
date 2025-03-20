/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:52 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 15:13:43 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !fichier a delete pour le rendu

#include <cub.h>

t_cub   init_fake_data(void)
{
	t_cub   fake;
	char    **map;

	map = lp_alloc(sizeof(char *) * 15);
	fake.no = lp_alloc(sizeof(char) * 19);
	fake.so = lp_alloc(sizeof(char) * 19);
	fake.we = lp_alloc(sizeof(char) * 19);
	fake.ea = lp_alloc(sizeof(char) * 19);
	fake.floor = lp_alloc(sizeof(char) * 10);
	fake.ceiling = lp_alloc(sizeof(char) * 9);

	ft_strlcpy(fake.no, "../textures/no.png", 19);
	ft_strlcpy(fake.so, "../textures/so.png", 19);
	ft_strlcpy(fake.we, "../textures/we.png", 19);
	ft_strlcpy(fake.ea, "../textures/ea.png", 19);
	ft_strlcpy(fake.floor, "220,100,0", 10);
	ft_strlcpy(fake.ceiling, "225,30,0", 9);

	map[0] = ft_strdup("        1111111111111111111111111");
	map[1] = ft_strdup("        1000000000110000000000001");
	map[2] = ft_strdup("        101100000111000100W000001");
	map[3] = ft_strdup("        1001000000000000000000001");
	map[4] = ft_strdup("111111111011000001110000000000001");
	map[5] = ft_strdup("100000000011000001110111100011111");
	map[6] = ft_strdup("11110111111111011100000010001");
	map[7] = ft_strdup("11110111111111011101010010001");
	map[8] = ft_strdup("11000000110101011100000010001");
	map[9] = ft_strdup("10000000000000001100000010001");
	map[10] = ft_strdup("10000000000000001101010010001");
	map[11] = ft_strdup("1100000111010101111101111000111");
	map[12] = ft_strdup("11110111 1110101 101111010001");
	map[13] = ft_strdup("11111111 1111111 111111111111");
	map[14] = NULL;

	fake.map = map;
	return (fake);
}

void print_data(t_cub data)
{
	int i;

	printf("NO: %s\n", data.no);
	printf("SO: %s\n", data.so);
	printf("WE: %s\n", data.we);
	printf("EA: %s\n", data.ea);
	printf("Floor: %s\n", data.floor);
	printf("Ceiling: %s\n", data.ceiling);
	printf("Map:\n");
	i = 0;
	while (data.map[i])
	{
		printf("%s\n", data.map[i]);
		i++;
	}
}
void    free_cub(t_cub *data)
{
	int i;

	if (data->no)
		lp_free(data->no);
	if (data->so)
		lp_free(data->so);
	if (data->we)
		lp_free(data->we);
	if (data->ea)
		lp_free(data->ea);
	if (data->floor)
		lp_free(data->floor);
	if (data->ceiling)
		lp_free(data->ceiling);
	if (data->map)
	{
		i = 0;
		while (data->map[i])
		{
			lp_free(data->map[i]);
			i++;
		}
		lp_free(data->map);
	}
}

