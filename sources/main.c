/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:14:59 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/14 11:54:15 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int main(void) {
    t_cub data;
    t_player player;

    // Initialiser data avec les valeurs appropriées
    data = init_fake_data();

    initialize_player(&player, &data);

    t_vector intersection;
    for (int i = 0; i < WIDTH; i++) {
		int hit;
        double angle = (-FOV / 2) + ((double)i / (WIDTH - 1)) * FOV;
        ray_cast(&player, angle, &hit, &intersection);

        // Debug print for rays that hit a wall
        if (hit) {
			double distance = hypot(intersection.x - player.pos.x, intersection.y - player.pos.y);
            double correctedDistance = distance * cos(degree_to_radian(angle));
            printf("Ray %d: Angle %f, Hit at (%f, %f), Distance: %f\n", i, angle, intersection.x, intersection.y, correctedDistance);
        }
    }

	printf("-------------------------------------------\n\n");

	printf("Player Position: (%f, %f)\n", player.pos.x, player.pos.y);
	printf("Player Direction: (%f, %f)\n", player.dir.x, player.dir.y);

	printf("-------------------------------------------\n\n");

	test_macro(&player, &data);

	print_data(data);
    free_cub(&data);
    return 0;
}

