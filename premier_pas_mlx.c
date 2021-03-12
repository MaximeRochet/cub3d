#include "mlx.h"

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int i;
	int y;

	i = 0;
	y = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "first_step");
	while(i++ < 500)
	{
		while (y++ < 500)
			if (y % 5 && y % 4)
				mlx_pixel_put(mlx_ptr, win_ptr, i, y, 0xFFFFFF);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, i, y, 0x000000);
		y=0;

	}
	while(i++ < 1000)
	{
		while (y++ < 500)
			mlx_pixel_put(mlx_ptr, win_ptr, i, y, 0x3409A3);
		y=0;
	}
	mlx_loop(mlx_ptr);
}
