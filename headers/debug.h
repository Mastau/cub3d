/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:08:27 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/12 15:27:51 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ! fichier a delet pour le rendu

#ifndef DEBUG_H
# define DEBUG_H

# include <cub.h>

t_cub	init_fake_data(void);
void	print_data(t_cub data);
void	free_cub(t_cub *data);

#endif
