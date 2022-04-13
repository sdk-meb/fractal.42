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

double map(double x, double in_min, double in_max, double out_min, double out_max) {
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

long	mandelbrot(double x, double y, long color)
{
    int f;
    double w;

    double xx = map(x, 0, 2400, -2.00, 0.47);
    double yy = map(1300 - y, 0, 1300, -1.12, 1.12);

    if (x == 0 || y == 0)
        return (color);
    w = 0;
    f = 0;
	double x2 = 0;
    double y2 = 0;
    w = 0;

    while (x2 + y2 <= 4 && f++ < 100)
    {
        x = x2 - y2 + xx;
        y = w - x2 - y2 + yy;
        x2 = x * x;
        y2 = y * y;
        w = (x + y) * (x + y);
    }
	return ((long)map(f,0,100,0,0x000ff0));
}
