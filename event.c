/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:04:09 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/18 08:19:01 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/apix.h"

t_vars	*call_name(t_vars *cc, int hook)
{
	if (cc->name == 'm')
		return (draw_(cc, mandelbrot, hook));
	else if (cc->name == 'j')
		return (draw_(cc, julia, hook));
	return (draw_(cc, burning_ship, hook));
}

int	mouse_hook(int button, int x, int y, t_vars *cc)
{
	if (button == 1)
		return (cc->access_mv = abs(cc->access_mv - 1));
	cc->y = ((x) * (cc->rn.lowest - cc->rn.top) / (IMG_WIDTH)) + cc->rn.top;
	cc->x = ((IMG_HEIGHT - y) * (cc->rn.left - cc->rn.right)
			/ (IMG_HEIGHT)) + cc->rn.right;
	call_name(cc, button);
	return (1);
}

int	get_mouse_pos(unsigned x, unsigned y, t_vars *cc)
{
	if (y < IMG_WIDTH && x < IMG_HEIGHT && cc->name == 'j' && cc->access_mv)
	{
		cc->c.re = ((x) * (cc->rn.lowest - cc->rn.top)
				/ (IMG_WIDTH)) + cc->rn.top;
		cc->c.img = ((IMG_HEIGHT - y) * (cc->rn.left - cc->rn.right)
				/ (IMG_HEIGHT)) + cc->rn.right;
		call_name(cc, 0);
	}
	return (0);
}

int	key_hook(int key_code, t_vars *cc)
{
	if (key_code == 53)
		exit (0);
	else if ((key_code == 8 && cc->color > 0)
		|| (key_code == 6 && cc->color < 0x00ffffff))
		cc->color += (key_code - 7) * 10;
	call_name(cc, key_code);
	return (0);
}
