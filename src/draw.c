#include "fdf.h"

void	draw_simple_line(t_fdf *fdf)
{
	while (fdf->img->instances->x <= 100)
	{
		fdf->img->instances->x += 1;
		fdf->img->instances->y += 1;
		mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			fdf->img->instances->y, BLUE); 
	}
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img); // Once the application request an exit, cleanup.
	mlx_terminate(fdf->mlx);
	free(fdf);
}
