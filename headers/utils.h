/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:18:06 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/25 14:13:58 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <cub.h>

unsigned int	convert_rgb_str_to_color(char *rgb_str);
int				check_collision(t_cub *data, double x, double y, char axis);

#endif
