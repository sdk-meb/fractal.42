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
#include "apix.h"

t_vars	drew_(t_vars cc, long (*f)( double, double, long))
{
	char	*buffer;
	long	color;
	uint	x;
	uint	y;
	int		image_depth;
	int		size_line;
	int		endian;
	int		pixel;

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
			color = f((double)x++, (double)y, cc.color++);
			buffer[pixel + 0] = (color);
			buffer[pixel + 1] = (color >> 8);
			buffer[pixel + 2] = (color >> 16);
			buffer[pixel + 3] = (color >> 24);
		}
		y++;
	}
	mlx_put_image_to_window(cc.mlx, cc.win, cc.img, 0, 0);
	return (cc);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	printf ("mouse_button /%d_____(x, y) (%d, %d) ___%p\n", button, x, y, (char *)param);
	return (1);
}

t_vars	creat_new(long (*f)( double, double, long))
{
	t_vars	cc;

	cc.mlx = mlx_init();
	cc.width_win = 2400;
	cc.height_win = 1300;
	if (!cc.mlx)
	{
		printf("initialization failed :0");
		exit (0);
	}
	cc.win = mlx_new_window(cc.mlx, cc.width_win , cc.height_win, "MEB");
	cc.img = mlx_new_image(cc.mlx,cc.width_win, cc.height_win);
	if (!cc.img || !cc.win)
	{
		write(1, "window or image creat deny\n", 27);
		exit(0);
	}
	return (drew_(cc,f));
}

int	main(void)
{
	t_vars	cc;

	cc = creat_new(mandelbrot);
	mlx_mouse_hook(cc.win, mouse_hook, "mouse");
	mlx_loop(cc.mlx);
	mlx_clear_window(cc.mlx, cc.win);
	return (mlx_destroy_window(cc.mlx, cc.win));
}
