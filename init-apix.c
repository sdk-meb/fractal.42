/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-apix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 06:02:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/05/18 08:14:26 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/apix.h"

t_vars	creat_new(char fract_name)
{
	t_vars	cc;

	cc.mlx = mlx_init();
	cc.name = fract_name;
	cc.color = 0x00ffffff;
	cc.access_mv = 0;
	cc.y = 0;
	cc.x = 0;
	if (!cc.mlx)
	{
		ft_printf("\n     initialization failed : 1");
		win_off(&cc);
	}
	cc.win = mlx_new_window(cc.mlx, WIN_WIDTH, WIN_HEIGHT, "FRACTOL");
	cc.img = mlx_new_image(cc.mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!cc.img || !cc.win)
	{
		write(1, "window or image creat deny\n", 27);
		win_off(&cc);
	}
	return (*call_name(&cc, 34));
}

void	practise(char acronymes)
{
	t_vars	cc;

	cc = creat_new(acronymes);
	mlx_mouse_hook(cc.win, mouse_hook, &cc);
	mlx_key_hook(cc.win, key_hook, &cc);
	mlx_hook(cc.win, 6, 0, get_mouse_pos, &cc);
	mlx_hook(cc.win, 17, 0, win_off, &cc);
	mlx_loop(cc.mlx);
	mlx_clear_window(cc.mlx, cc.win);
	mlx_destroy_window(cc.mlx, cc.win);
}
