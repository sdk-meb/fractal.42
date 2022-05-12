/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drew.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:05:23 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/12 12:05:27 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/apix.h"

t_vars	drew_(t_vars cc, long (*f)( double, double, t_rng), int hook)
{
	char	*buffer;
	long	color;
	uint	x;
	uint	y;
	int		image_depth;
	int		size_line;
	int		endian;
	int		pixel;
	t_rng	rn;

	rn = set_range(hook);
	y = 0;
	cc.width_img = cc.width_win;
	cc.height_img = cc.height_win;
	buffer = mlx_get_data_addr(cc.img, &image_depth, &size_line, &endian);
	cc.color = mlx_get_color_value(cc.mlx, 0x006010ff);
	while (y < cc.height_img)
	{
		x = 0;
		while (x < cc.width_img)
		{
			pixel = (x + y * cc.width_img) * 4;
			color = f((double)x++, (double)y,rn);
			buffer[pixel + 0] = (color);
			buffer[pixel + 1] = (color >> 8);
			buffer[pixel + 2] = (color >> 16);
			buffer[pixel + 3] = (color >> 24);
		}
		y++;
	}
	//printf("top-->%f,, low-->%f,, right-->%f,,  left-->%f\n", rn.top, rn.lowest, rn.right, rn.left);
	mlx_put_image_to_window(cc.mlx, cc.win, cc.img, 0, 0);
	return (cc);
}
