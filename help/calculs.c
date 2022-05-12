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
#include "../include/apix.h"

double  map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

t_rng set_range(int hook)
{
    static t_rng rn;

    if (hook == 2)
    {
		rn.top = -2.10;
		rn.lowest = 1.57;
		rn.right = -1.22;
		rn.left = 1.22;
    }
    else if (hook == 4)
    {
      rn.top += 0.001;
		  rn.lowest -= 0.001;
		  rn.right += 0.001;
		  rn.left -= 0.001;
    }
    else if (hook == 5)
    { 
      rn.top -= 0.001;
		  rn.lowest += 0.001;
		  rn.right -= 0.001;
		  rn.left += 0.001;
    }
    return (rn);
}

long	mandelbrot(double x, double y, t_rng rn)
{
    int f;
    double w;
    double xx;
    double yy;
    double y2;
    double x2;

    /* RANGE OF MANDELBROT SET [-2.00, 1,47]<-->[-1.12, 1.12] */
    xx = map(x, 0, 1400, rn.top, rn.lowest);
    yy = map(1000 - y, 0, 1000, rn.right, rn.left);
    w = 0;
    f = 0;
	  x2 = 0;
    y2 = 0;
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
