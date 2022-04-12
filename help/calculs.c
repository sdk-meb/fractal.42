/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:09:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/04/12 10:12:52 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "calculs.h"

int map(int x, int in_min, int in_max, int out_min, int out_max) {
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

long	mandelbrot(int x, int y, long color)
{
    int f;
    int z;

    z = 0;
    f = 50;
	while (f-- > 0)
    {
        z = (z * z) + x + y;
        if (z < 4)
		    return(color);
    }
	return (0);
}