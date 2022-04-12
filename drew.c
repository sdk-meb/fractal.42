/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drew.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:05:23 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/18 07:49:22 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/apix.h"

t_vars	*drew_(t_vars *cc, long (*f)( double, double, t_vars *), int hook)
{
	unsigned int	x;
	unsigned int	y;
	long			color;

	set_range(hook, cc);
	y = 0;
	cc->buffer = mlx_get_data_addr(cc->img, &cc->image_depth, &cc->size_line,
			&cc->endian);
	while (y < IMG_HEIGHT)
	{
		x = 0;
		while (x < IMG_WIDTH)
		{
			cc->pixel = (x + y * IMG_WIDTH) * 4;
			color = f((double)x++, (double)y, cc);
			cc->buffer[cc->pixel + 0] = (color);
			cc->buffer[cc->pixel + 1] = (color >> 8);
			cc->buffer[cc->pixel + 2] = (color >> 16);
			cc->buffer[cc->pixel + 3] = (color >> 24);
		}
		y++;
	}
	mlx_put_image_to_window(cc->mlx, cc->win, cc->img, 0, 0);
	return (cc);
}
