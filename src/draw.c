#include "fdf.h"

void	print_mesh(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= fdf->mtrx->size->x)
	{
		y = 0;
		while (y <= fdf->mtrx->size->y)
		{
			//draw_to_nxt_pt(&fdf);
			if (y % 2 == 0)
				mlx_put_pixel(fdf->img, x, y, rgba(0.3)); 
			else
				mlx_put_pixel(fdf->img, x, y, rgba(0.3)); 
			y += 1;
		}
		x += 1;
	}
	
}

void	print_mesh_at_origin(t_fdf *fdf)
{
	t_vec2	origin;
	t_vec2	orig_cpy;

	origin.x = round(fdf->mtrx->start_draw->x);
	origin.y = round(fdf->mtrx->start_draw->y);
	orig_cpy.x = origin.x;
	orig_cpy.y = origin.y;
	printf("pos.x dummy origin: %f\n", origin.x);
	printf("pos.y dummy origin: %f\n", origin.y);

	while (origin.x  <= fdf->mtrx->size->x + X_ORIGIN_OFF)
	{
		origin.y = orig_cpy.y;
		while (origin.y <= fdf->mtrx->size->y + Y_ORIGIN_OFF)
		{
			if ((int)origin.y % 2 == 0)
				mlx_put_pixel(fdf->img, origin.x , origin.y , rgba(0.3));
			else
				mlx_put_pixel(fdf->img, origin.x , origin.y , rgba(0.3));
			origin.y += 1;
		}
		origin.x += 1;
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
