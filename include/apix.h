/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apix.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:25:10 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/04/12 08:53:47 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef APIX_H
#define APIX_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h> 
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

#define uint unsigned

typedef struct s_range{
	double  top;
	double	lowest;
	double	right;
	double	left;
}						t_rng;

typedef struct	s_vars {
	void	*mlx;

	void	*win;
	uint		width_win;
	uint		height_win;

	void	*img;
	uint		width_img;
	uint		height_img;

	long	color;
}						t_vars;

int		mouse_hook(int button, int x, int y, void *param);
int		create_trgb(int t, int r, int g, int b);

double	map(double x, double in_min, double in_max, double out_min, double out_max);

long	mandelbrot(double x, double y, t_rng rn);

char	*check_name(int c, char **name);

t_rng	set_range(int hook);

t_vars save(t_vars cc);
t_vars	drew_(t_vars cc, long (*f)( double, double, t_rng), int hook);

#endif
