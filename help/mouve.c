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
    (*y) += 0.01;
    (*x) += 0.01;
}

void    left_lowest(double *x, double *y)
{
    (*y) -= 0.01;
    (*x) -= 0.01;
}

void    zoom_in()
{
    
}

void    zoom_out()
{

}
