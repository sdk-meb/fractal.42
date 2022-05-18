/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:09:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/18 08:04:27 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/apix.h"

void	init_range(t_vars *cc)
{
	if (cc->name == 'm' || cc->name == 'b')
	{
		cc->rn.top = -2.50;
		cc->rn.lowest = 1.50;
		cc->rn.right = -1.22;
		cc->rn.left = 1.22;
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

void	set_range(int hook, t_vars *cc)
{
	if (hook == 34)
		init_range(cc);
	else if (hook == 123)
		down_right(&cc->rn.top, &cc->rn.lowest);
	else if (hook == 124)
		left_lowest(&cc->rn.top, &cc->rn.lowest);
	else if (hook == 125)
		down_right(&cc->rn.left, &cc->rn.right);
	else if (hook == 126)
		left_lowest(&cc->rn.left, &cc->rn.right);
	else if (hook == 86)
		heigh_correction(&cc->rn.top, &cc->rn.lowest);
	else if (hook == 88)
		width_correction(&cc->rn.top, &cc->rn.lowest);
	else if (hook == 91)
		heigh_correction(&cc->rn.left, &cc->rn.right);
	else if (hook == 84)
		width_correction(&cc->rn.left, &cc->rn.right);
	else if (hook == 4)
		zoom_in(cc);
	else if (hook == 5)
		zoom_out(cc);
}

long	mandelbrot(double x, double y, t_vars *cc)
{
	t_clx	z;
	t_clx	zn;
	int		iter;

	cc->c.re = (x * (cc->rn.lowest - cc->rn.top) / (WIN_WIDTH)) + cc->rn.top;
	cc->c.img = ((WIN_HEIGHT - y) * (cc->rn.left - cc->rn.right)
			/ (WIN_HEIGHT)) + cc->rn.right;
	iter = 0;
	z.img = 0;
	z.re = 0;
	while ((z.re * z.re + z.img * z.img) < 4 && iter++ < MAX_ITER)
	{
		zn.re = (z.re * z.re) - (z.img * z.img);
		zn.img = 2 * z.re * z.img;
		z.re = zn.re + cc->c.re;
		z.img = zn.img + cc->c.img;
	}
	return ((iter) * (cc->color) / (51));
}

long	julia(double x, double y, t_vars *cc)
{
	t_clx	z;
	t_clx	zn;
	int		iter;

	z.re = ((x) * (cc->rn.lowest - cc->rn.top) / (WIN_WIDTH)) + cc->rn.top;
	z.img = ((WIN_HEIGHT - y) * (cc->rn.left - cc->rn.right)
			/ (WIN_HEIGHT)) + cc->rn.right;
	iter = 0;
	while ((z.re * z.re + z.img * z.img) < 4 && iter++ < MAX_ITER)
	{
		zn.re = (z.re * z.re) - (z.img * z.img);
		zn.img = 2 * z.re * z.img;
		z.re = zn.re + cc->c.re;
		z.img = zn.img + cc->c.img;
	}
	return ((iter) * (cc->color) / (51));
}

long	meb(double x, double y, t_vars *cc)
{
	t_clx	z;
	t_clx	zn;
	int		iter;

	cc->c.re = (x * (cc->rn.lowest - cc->rn.top) / (WIN_WIDTH)) + cc->rn.top;
	cc->c.img = ((WIN_HEIGHT - y) * (cc->rn.left - cc->rn.right)
			/ (WIN_HEIGHT)) + cc->rn.right;
	iter = 0;
	z.img = 0;
	z.re = 0;
	while ((z.re * z.re + z.img + z.img) < 4 && iter++ < MAX_ITER)
	{
		zn.re = (z.re * z.re) - (z.img * z.img) / sin(z.img * 0.1 + 0.3);
		zn.img = 2 * z.re * z.img;
		z.re = zn.re + cc->c.re;
		z.img = zn.img + cc->c.img;
	}
	return ((iter) * (cc->color) / (51));
}
