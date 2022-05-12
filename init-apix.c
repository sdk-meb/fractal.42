/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-apix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 06:02:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/04/13 06:02:43 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/apix.h"

t_vars	creat_new(long (*f)( double, double, t_rng))
{
	t_vars	cc;

	cc.mlx = mlx_init();
	cc.width_win = 1400;
	cc.height_win = 1000;
	if (!cc.mlx)
	{
		ft_printf("initialization failed :1");
		exit (1);
	}
	cc.win = mlx_new_window(cc.mlx, cc.width_win , cc.height_win, "FRACTOL");
	cc.img = mlx_new_image(cc.mlx,cc.width_win, cc.height_win);
	if (!cc.img || !cc.win)
	{
		write(1, "window or image creat deny\n", 27);
		exit(1);
	}
	return (drew_(save(cc), f, 2));
}

t_vars	practise(int c, char *acronymes)
{
	t_vars  cc;
	while (c--)
	{
		if (acronymes[c] == 'm')
			cc = creat_new(mandelbrot);
	}
	return (cc);
}

int	main(int c, char **name)
{
	t_vars	cc;

	cc = practise(c, check_name(c, name));
	mlx_mouse_hook(cc.win, mouse_hook, "mouse");
	mlx_loop(cc.mlx);
	mlx_clear_window(cc.mlx, cc.win);
	return (mlx_destroy_window(cc.mlx, cc.win));
	return 0;
}
