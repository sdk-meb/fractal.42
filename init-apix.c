#include "apix.h"

t_vars drew_(t_vars cc, long (*fun)(int,int ,long))
{
	char 	*buffer;
	long 	color;
	uint	x;
	uint	y;
	int 	image_depth;
	int 	size_line;
	int		endian;

	y = 0;
	cc.width_img = cc.width_win;
	cc.height_img = cc.height_win;
	buffer = mlx_get_data_addr(cc.img, &image_depth, &size_line, &endian);
    cc.color = mlx_get_color_value(cc.mlx, 0x006010ff);
	while(y < cc.height_img)
	{
		x = 0;
		while(x < cc.width_img)
		{
			int pixel = (x + y * cc.width_img) * 4;
			double a = map(x, 0 ,cc.width_img, -2, 2);
			double b = map(y,0, cc.height_img, -2, 2);
			color = fun(a, b, cc.color);
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

int mouse_hook(int button,int x,int y,void *param)
{
	printf("mouse_button /%d_____(x, y) (%d, %d) ___%p\n",button, x,y,(char *)param);
	return (1);
}

t_vars creat_new()
{
	t_vars	cc;
	cc.width_win = 1400 ,cc.height_win = 1400;
	cc.mlx = mlx_init();
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
	return (drew_(cc,mandelbrot));
}

int	main(void)
{
	t_vars	cc;

	cc = creat_new();
	mlx_mouse_hook(cc.win, mouse_hook, "mouse");
	mlx_loop(cc.mlx);
	mlx_clear_window(cc.mlx, cc.win);
	return (mlx_destroy_window(cc.mlx, cc.win));
}
