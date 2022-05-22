#include "fdf.h"

void	print_matrix(t_fdf *fdf, t_mtx *mtx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (fdf)
		printf("fdf is not null! \n");
	while (mtx->mtx[x])
	{
		y = 0;
		while (mtx->mtx[x][y] != '\0' && mtx->mtx[x][y] != '\n')
		{
			printf("%c", mtx->mtx[x][y]);
			// fdf->img->instances->x += x;
			// fdf->img->instances->y += y;
			// mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			// 	fdf->img->instances->y, BLUE);
			y++;

		}
		printf("\n");
		x++;
	}
}


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
	//free(fdf);
}
