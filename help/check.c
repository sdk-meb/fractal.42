/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:30:13 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/12 09:30:16 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/apix.h"

char check_name(int c, char *name)
{
	if (c != 2)
		exit(ft_printf("we can't find any fractol set name"));
	if (!ft_memcmp(name, "mandelbrot", 11))
		return ('m');
	else if (!ft_memcmp(name, "julia", 6))
		return ('j');
	else if (!ft_memcmp(name, "meb", 4))
		return ('b');
	exit(ft_printf("we can't find this fractol set : %s", name));
}