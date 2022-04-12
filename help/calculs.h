/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shift.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:16:05 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/04/12 10:17:12 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BITS_H
#define BITS_H

#include "../apix.h"

double     map(int x, int in_min, int in_max, int out_min, int out_max);
long	mandelbrot(int x, int y, long color);

int     create_trgb(int t, int r, int g, int b);



#endif
