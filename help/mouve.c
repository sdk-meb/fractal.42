/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:03:26 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/15 10:03:28 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/apix.h"

void down_right(double *x, double *y)
{
    (*y) +=  0.03;
    (*x) += 0.03;
}

void    left_lowest(double *x, double *y)
{
    (*y) -=  0.03;
    (*x) -=  0.03;
}

void width_correction(double *x, double *y)
{
    (*y) *=  1.1;
    (*x) *= 1.1;
}

void     heigh_correction(double *x, double *y)
{
    (*y) *=  0.9;
    (*x) *=  0.9;
}

void    zoom_in(t_vars *cc)
{
    cc->rn.top += cc->rn.top * 0.1 + cc->x ;
	cc->rn.lowest += cc->rn.lowest * 0.1 + cc->x ;
	cc->rn.right += cc->rn.right * 0.1 + cc->y;
    cc->rn.left += cc->rn.left * 0.1 + cc->y;
}

void    zoom_out(t_vars *cc)
{
    cc->rn.top -= cc->rn.top * 0.1 + cc->x;
	cc->rn.lowest -= cc->rn.lowest * 0.1 + cc->x;
	cc->rn.right -= cc->rn.right * 0.1 + cc->y;
    cc->rn.left -= cc->rn.left * 0.1 + cc->y;
}
