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

void  init_range(t_vars *cc)
{
  if (cc->name == 'm')
  {
    cc->rn.top = -1.50;
	  cc->rn.lowest = 1.50;
	  cc->rn.right = -1.12;
	  cc->rn.left = 1.12;
  cc->c.img = 0;
  cc->c.re = 0;
  }
  if (cc->name == 'j')
  {
    cc->rn.top = -1.50;
	  cc->rn.lowest = 1.5;
	  cc->rn.right = -1.5;
	  cc->rn.left = 1.5;
    cc->c.img = 0.11;
    cc->c.re = -0.75;
  }
}

void set_range(int hook, t_vars *cc)
{
  if (hook == 34)/* reset range of fractal*/
    init_range(cc);
  else if (hook == 123)
    down_right(&cc->rn.top, &cc->rn.lowest);
  else if (hook == 124)
    left_lowest(&cc->rn.top, &cc->rn.lowest);
  else if (hook == 125)
      down_right(&cc->rn.left, &cc->rn.right);
  else if (hook == 126)
     left_lowest(&cc->rn.left, &cc->rn.right);
  else if (hook == 4)/* zoom in == range \> */
  {
    cc->rn.top /= 0.01;
		cc->rn.lowest /= 0.01;
		cc->rn.right /= 0.01;
	  cc->rn.left /= 0.01;
  }
  else if (hook == 5)/* zoom out == range /> */
  { 
    cc->rn.top *= 0.01;
		cc->rn.lowest *= 0.01;
		cc->rn.right *= 0.01;
    cc->rn.left *= 0.01;
  }
}

long	mandelbrot(double x, double y, t_vars cc)
{
  t_clx z;
  t_clx zn;
  int   iter;

  cc.c.re = map(x, 0, WIN_WIDTH, cc.rn.top, cc.rn.lowest);
  cc.c.img = map(WIN_HEIGHT - y, 0, WIN_HEIGHT, cc.rn.right, cc.rn.left);
  iter = 0;
  z.img = 0;
  z.re = 0;
	while ((z.re * z.re + z.img * z.img) < 4 && iter++ < MAX_ITER)
	{
		zn.re = (z.re * z.re) - (z.img * z.img);
		zn.img = 2 * z.re * z.img;
		z.re = zn.re + cc.c.re;
		z.img = zn.img + cc.c.img;
	}
	return (map(iter, 0, 51, 0, cc.color));
}

long  julia(double x, double y, t_vars cc)
{
  t_clx z;
  t_clx zn;
  int   iter;

  z.re = map(x, 0, WIN_WIDTH, cc.rn.top, cc.rn.lowest);
  z.img = map(WIN_HEIGHT - y, 0, WIN_HEIGHT, cc.rn.right, cc.rn.left);
  iter = 0;
	while ((z.re * z.re + z.img * z.img) < 4 && iter++ < MAX_ITER)
	{
		zn.re = (z.re * z.re) - (z.img * z.img);
		zn.img = 2 * z.re * z.img;
		z.re = zn.re + cc.c.re;
		z.img = zn.img + cc.c.img;
	}
	return (map(iter, 0, 51, 0, cc.color));
}

long  meb(double x, double y, t_vars cc)
{
  t_clx z;
  t_clx zn;
  int   iter;

  iter = 0;
  z.img = cc.c.img + map(WIN_HEIGHT - y, 0, WIN_HEIGHT, cc.rn.right, cc.rn.left);
  z.re = cc.c.re + map(x, 0, WIN_WIDTH, cc.rn.top, cc.rn.lowest);
	while ((z.re * z.re + z.img * z.img) > 4 && iter++ < MAX_ITER)
	{
		z.re = (z.re * z.re) - (z.img * z.img);
		z.img = 2 * z.re * z.img;
		zn.re = zn.re + cc.c.re;
		zn.img = zn.img + cc.c.img;
	}
    return (0);
}
