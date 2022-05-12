/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:04:09 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/12 12:04:11 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/apix.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_vars cc;

	cc.mlx = NULL;
	cc = save(cc);
	(void)param;
	cc.width_win = map(x, 0, cc.width_img, -(cc.width_img / 2), cc.width_img / 2);
	cc.height_win = map(-y, -cc.height_img, 0, -(cc.height_img / 2), cc.height_img / 2);

	if (button != 1)
		drew_(cc, mandelbrot, button);
	else
		ft_printf ("mouse_button /%d_____(x, y) (%d, %d) ___(%d___%d)\n", button, x, y,cc.width_win ,cc.height_win);
	return (1);
}