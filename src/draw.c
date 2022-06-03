#include "fdf.h"


/**
 * 	Cómo determinar cual es el siguiente punto a pintar, en una malla
 * donde la distancia entre pixel y pixel no existe, no hay necesidad.
 * pero al aumentar el tamaño de la malla, o  modificarla, hay que 
 * determinar la distancia entre pnt y pnt.
 * 
*/
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
			//draw_to_nxt_pt(&fdf);
			if (fdf->img->instances->y % 2 == 0)
				mlx_put_pixel(fdf->img, fdf->img->instances->x, 
				fdf->img->instances->y, rgba()); 
			else
				mlx_put_pixel(fdf->img, fdf->img->instances->x, 
				fdf->img->instances->y, BLU_CB); 
			//mesh[x][y]
			fdf->img->instances->y += 1;
		}
		fdf->img->instances->x += 1;
	}
	
}

// void	set_pixel(t_fdf *fdf)
// {
// 	//mlx_put_pixel()
	
// }

// void	draw_to_nxt_pt(t_fdf *fdf)
// {
// 	int dx;
// 	int	sx;
// 	int dy;
// 	int sy;
// 	int err[2]; /* error value e_xy */

// 	dx = abs(x1 - fdf->img->instances->x);
// 	dy = -abs(y1 - fdf->img->instances->y);
// 	err[0] = dx + dy;
// 	set_sx(fdf->img->instances->x, x1, &sx);
// 	set_sy(fdf->img->instances->y, y1, &sy);

// 	while (true)
// 	{
// 		setPixel (fdf);
// 		if (fdf->img->instances->x == x1 && fdf->img->instances->y == y1)
// 			break;
// 		err[1] = 2 * err[0];
// 		if (err[1] >= dy)
// 		{
// 			err[0] += dy;
// 			fdf->img->instances->x += sx;
// 		} /* e_xy+e_x > 0 */
// 		if (err[1] <= dx)
// 		{
// 			err[0] += dx;
// 			fdf->img->instances->y += sy;
// 		} /* e_xy+e_y < 0 */
// 	}
// }


void	draw_simple_line(t_fdf *fdf, int max)
{
	int	start;
	start = fdf->img->instances->y;
	while (fdf->img->instances->x <= (max * 5))
	{
		//fdf->img->instances->x += 1;
		fdf->img->instances->y += 1;
		mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			fdf->img->instances->y, BLU_CB); 
	}
	fdf->img->instances->y = start;
	while (fdf->img->instances->x <= (max * 5))
	{
		//fdf->img->instances->x += 1;
		fdf->img->instances->y += 1;
		mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			fdf->img->instances->y, BLU_CB); 
	}
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img); // Once the application request an exit, cleanup.
	mlx_terminate(fdf->mlx);
	//free(fdf);
}
