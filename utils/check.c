/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:30:13 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/18 07:56:48 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/apix.h"

char	check_name(int c, char *name)
{
	if (c != 2)
		exit(ft_printf("\n     Enter one name set to draw"));
	if (!ft_memcmp(name, "mandelbrot", 11))
		return ('m');
	else if (!ft_memcmp(name, "julia", 6))
		return ('j');
	else if (!ft_memcmp(name, "meb", 4))
		return ('b');
	exit(ft_printf("\n    we can't find this fractol set : %s", name));
}

void	width_correction(double *x, double *y)
{
	(*y) *= 1.1;
	(*x) *= 1.1;
}

void	heigh_correction(double *x, double *y)
{
	(*y) *= 0.9;
	(*x) *= 0.9;
}

void	win_off(t_vars *cc)
{
	mlx_clear_window(cc->mlx, cc->win);
	mlx_destroy_window(cc->mlx, cc->win);
	exit(1);
}
