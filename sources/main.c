/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:14:59 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/11 18:33:15 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <stdio.h>
#include "debug.h"

int main(void)
{
	t_cub data;

	data = init_fake_data();
	print_data(data);
	return (0);
}
