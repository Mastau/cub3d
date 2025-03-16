/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:14:59 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/16 15:02:18 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

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
	test_macro(&player, &data);
	free_cub(&data);
	return (0);
}
