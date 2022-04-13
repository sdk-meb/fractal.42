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
#include "help/calculs.h"

#define uint unsigned

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

#endif
