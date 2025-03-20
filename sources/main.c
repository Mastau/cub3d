/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:14:59 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/20 18:43:32 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <debug.h>
#include <minimap.h>
#include <rendering.h>

int	main(void)
{
	t_cub		data;
	t_player	player;

	data = init_fake_data();
	initialize_player(&player, &data);
	printf("-------------------------------------------\n\n");
	printf("Player Position: (%f, %f)\n", player.pos.x, player.pos.y);
	printf("Player Direction: (%f, %f)\n", player.dir.x, player.dir.y);
	printf("-------------------------------------------\n\n");
	print_data(data);
	data.player = &player;
	init_3d_rendering(&data);
	free_cub(&data);
	return (0);
}
