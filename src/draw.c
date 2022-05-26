#include "fdf.h"

void	print_matrix(t_fdf *fdf, t_mtrx *mtrx)
{
	int	x;
	int	y;
	int	start;

	x = 0;
	y = 0;
	start = fdf->img->instances->y;
	if (fdf)
		printf("fdf is not null! \n");
	// while (mtx->mtx[x] && x < 3)
	// {
	// 	y = 0;
	// 	fdf->img->instances->y = start;
		while (mtrx->mtrx[x][y] != '\0' && mtrx->mtrx[x][y] != '\n')
		{
			printf("%c", mtrx->mtrx[x][y]);
			//fdf->img->instances->x += x;
			// fdf->img->instances->y += y;
			// mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			// 	fdf->img->instances->y, BLUE);
			y++;
		}
	
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
