/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:59:24 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/17 13:04:58 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <cub.h>

t_cub	init_fake_data(void);
void	print_data(t_cub data);
void	free_cub(t_cub *data);

#endif
