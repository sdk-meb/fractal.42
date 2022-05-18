/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:03:26 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/18 07:52:08 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/apix.h"

void	down_right(double *x, double *y)
{
	(*y) += 0.03;
	(*x) += 0.03;
}

void	left_lowest(double *x, double *y)
{
	(*y) -= 0.03;
	(*x) -= 0.03;
}

void	zoom_in(t_vars *cc)
{
	cc->rn.top -= cc->y;
	cc->rn.lowest -= cc->y;
	cc->rn.right -= cc->x;
	cc->rn.left -= cc->x;
	cc->rn.top += cc->rn.top * 0.1 ;
	cc->rn.lowest += cc->rn.lowest * 0.1 ;
	cc->rn.right += cc->rn.right * 0.1;
	cc->rn.left += cc->rn.left * 0.1;
	cc->rn.top += cc->y;
	cc->rn.lowest += cc->y;
	cc->rn.right += cc->x;
	cc->rn.left += cc->x;
}

void	zoom_out(t_vars *cc)
{
	cc->rn.top -= cc->y;
	cc->rn.lowest -= cc->y;
	cc->rn.right -= cc->x;
	cc->rn.left -= cc->x;
	cc->rn.top -= cc->rn.top * 0.1;
	cc->rn.lowest -= cc->rn.lowest * 0.1;
	cc->rn.right -= cc->rn.right * 0.1;
	cc->rn.left -= cc->rn.left * 0.1;
	cc->rn.top += cc->y;
	cc->rn.lowest += cc->y;
	cc->rn.right += cc->x;
	cc->rn.left += cc->x;
}
