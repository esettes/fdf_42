#include "fdf.h"

void	print_mesh(t_fdf *fdf)
{
	int	x;
	int	y;
	int	**mesh;

	x = 0;
	y = 0;
	mesh = fdf->mtrx->mtrx;
	while (fdf->img->instances->x - OFFSET <= fdf->mtrx->size->x)
	{
		fdf->img->instances->y = OFFSET;
		while (fdf->img->instances->y - OFFSET <= fdf->mtrx->size->y)
		{
			if (fdf->img->instances->y % 2 == 0)
				mlx_put_pixel(fdf->img, fdf->img->instances->x, 
				fdf->img->instances->y, YELLOW); 
			else
				mlx_put_pixel(fdf->img, fdf->img->instances->x, 
				fdf->img->instances->y, YELLOW); 
			//mesh[x][y]
			fdf->img->instances->y += 1;
		}
		fdf->img->instances->x += 1;
	}
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img); // Once the application request an exit, cleanup.
	mlx_terminate(fdf->mlx);
	
}


void	draw_simple_line(t_fdf *fdf, int max)
{
	int	start;
	start = fdf->img->instances->y;
	while (fdf->img->instances->x <= (max * 5))
	{
		//fdf->img->instances->x += 1;
		fdf->img->instances->y += 1;
		mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			fdf->img->instances->y, BLUE); 
	}
	fdf->img->instances->y = start;
	while (fdf->img->instances->x <= (max * 5))
	{
		//fdf->img->instances->x += 1;
		fdf->img->instances->y += 1;
		mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			fdf->img->instances->y, BLUE); 
	}
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img); // Once the application request an exit, cleanup.
	mlx_terminate(fdf->mlx);
	//free(fdf);
}
