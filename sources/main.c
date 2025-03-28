/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:42:45 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 15:40:56 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <fcntl.h>
#include <rendering.h>

static void	free_cub(t_cub *data)
{
	int	i;

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

void	check_display(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "DISPLAY=:0", 10) == 0
			&& ft_strlen(env[i]) == 10)
			return ;
		i++;
	}
	ft_putstr_fd("Error: DISPLAY environment\n", 2);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	t_cub		*data;
	t_player	player;
	int			fd;

	check_display(env);
	if (check_param(ac, av))
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
		return (1);
	if (map_fill(data))
		return (1);
	initialize_player(&player, data);
	data->player = &player;
	init_3d_rendering(data);
	free_cub(data);
	return (0);
}
