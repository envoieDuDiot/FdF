#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include "essai.h"

void linge(int x, int y, int xx, int yy, t_mlx *ptr)
{
	int dx = abs(xx-x), sx = x<xx ? 1 : -1;
	int dy = abs(yy-y), sy = y<yy ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;

	while(1)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, x, y, 0xFFFFFF);
		if (x == xx && y == yy)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y += sy;
		}
	}
}

int main()
{
	t_mlx *ptr;
	static void	*mlx;
	static void	*win;

	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(mlx, 50, 50, "lsls");
	linge(1, 1, 12, 20, ptr);
	mlx_loop(mlx);
	return (0);
}
