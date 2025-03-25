/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:54:20 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/21 12:07:28 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# include <cub.h>

void	rotate_player_left(t_cub *data);
void	rotate_player_right(t_cub *data);
void	move_player_forward(t_cub *data, double speed);
void	move_player_backward(t_cub *data, double speed);
void	move_player_left(t_cub *data, double speed);
void	move_player_right(t_cub *data, double speed);
void	key_press_hook(int key, void *param);
void	key_release_hook(int key, void *param);
void	update_game(void *param);

#endif
