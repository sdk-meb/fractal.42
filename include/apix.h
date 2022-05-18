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
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

#define uint unsigned
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define IMG_WIDTH 1000
# define IMG_HEIGHT 1000

# define MAX_ITER 50

typedef struct s_complexe{
	double re;
	double img;
}				t_clx;

typedef struct s_range{
	double  top;
	double	lowest;
	double	right;
	double	left;
}						t_rng;

typedef struct	s_vars {
	void	*mlx;

	void	*win;

	char 	name;
	void	*img;
	
	double		x;
	double		y;

	int		image_depth;
	int		size_line;
	int		endian;
	int		pixel;
	char	*buffer;

	bool	access_mv;
	long	color;
	t_rng		rn;
	t_clx		c;
}						t_vars;

void	red(void);
void	yellow(void);
void	blue(void);
void	purple(void);
void	reset(void);

int		mouse_hook(int button, int x, int y, t_vars *cc);
int		key_hook(int key_code, t_vars *cc);
int		create_trgb(int t, int r, int g, int b);
int		get_mouse_pos(uint x, uint y, t_vars *cc);

double	map(double x, double in_min, double in_max, double out_min, double out_max);

long	mandelbrot(double x, double y, t_vars *cc);
long	julia(double x, double y, t_vars *cc);
long	meb(double x, double y, t_vars *cc);

char	check_name(int c, char *name);

void	practise(char acronymes);
void	down_right(double *x, double *y);
void	left_lowest(double *x, double *y);
void	zoom_in(t_vars *cc);
void	zoom_out(t_vars *cc);
void 	width_correction(double *x, double *y);
void	heigh_correction(double *x, double *y);


void	set_range(int hook, t_vars *cc);

t_vars	*drew_(t_vars *cc, long (*f)( double, double, t_vars *), int hook);
t_vars *call_name(t_vars *cc, int hook);

#endif
