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

t_vars	call_name(t_vars cc, int hook)
{
	printf("%d____\n",hook);
	if (cc.name == 'm')
		return (drew_(cc, mandelbrot, hook));
	else if (cc.name == 'j')
		return (drew_(cc, julia, hook));
	return (drew_(cc, meb, hook));
}

int	mouse_hook(int button, int x, int y, t_vars *cc)
{
	if (button == 1)
		return (cc->access_mv = abs(cc->access_mv - 1));
	cc->y = map(x, 0,WIN_WIDTH,cc->rn.top, cc->rn.lowest);
	cc->x = map(1000 - y, 0, WIN_HEIGHT,cc->rn.right,cc->rn.left);
	call_name(*cc, button);
	return (1);
}

int get_mouse_pos(uint x, uint y, t_vars *cc)
{
	if (y < IMG_WIDTH && x < IMG_HEIGHT && cc->name == 'j' && cc->access_mv)
	{
		cc->c.re = map(x , 0,IMG_WIDTH , cc->rn.top, cc->rn.lowest);
		cc->c.img = map(IMG_HEIGHT - y, 0, IMG_HEIGHT, cc->rn.right, cc->rn.left);
		call_name(*cc, 0);
	}
	return 0;
}

int	key_hook(int key_code, t_vars *cc)
{
	if (key_code == 53)
		exit (0);
	else if ((key_code == 8  && cc->color > 0 )|| (key_code == 6 && cc->color < 0x00ffffff))
		cc->color += (key_code - 7) * 10;
	call_name(*cc, key_code);
	return 1;
}