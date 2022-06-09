#include "fdf.h"

// void	print_mesh(t_fdf *fdf)
// {
// 	int	x;
// 	int	y;
// 	int	**mesh;

// 	x = 0;
// 	y = 0;
// 	mesh = fdf->mtrx->mtrx;
	
// 	while (fdf->img->instances->x - OFFSET <= fdf->mtrx->size->x)
// 	{
// 		fdf->img->instances->y = OFFSET;
// 		while (fdf->img->instances->y - OFFSET <= fdf->mtrx->size->y)
// 		{
// 			//draw_to_nxt_pt(&fdf);
// 			if (fdf->img->instances->y % 2 == 0)
// 				mlx_put_pixel(fdf->img, fdf->img->instances->x, 
// 				fdf->img->instances->y, rgba(0.3)); 
// 			else
// 				mlx_put_pixel(fdf->img, fdf->img->instances->x, 
// 				fdf->img->instances->y, rgba(0.3)); 
// 			//mesh[x][y]
// 			fdf->img->instances->y += 1;
// 		}
// 		fdf->img->instances->x += 1;
// 	}
	
// }

void	print_mesh(t_fdf *fdf)
{
	int	x;
	int	y;
	int	**mesh;

	x = 0;
	y = 0;
	mesh = fdf->mtrx->mtrx;
	
	while (x <= fdf->mtrx->size->x)
	{
		y = 0;
		while (y <= fdf->mtrx->size->y)
		{
			//draw_to_nxt_pt(&fdf);
			if (y % 2 == 0)
				mlx_put_pixel(fdf->img, x, 
				y, rgba(0.3)); 
			else
				mlx_put_pixel(fdf->img, x, 
				y, rgba(0.3)); 
			//mesh[x][y]
			y += 1;
		}
		x += 1;
	}
	
}

void	print_mesh_at_origin(t_fdf *fdf)
{
	t_vec2			pos;
	t_vec2			dummy_origin;
	t_vec2			size_aux;
//	mlx_instance_t	*new_img;


	// original.x = fdf->mtrx->size->x / 2;
	// original.y = fdf->mtrx->size->y / 2;
	dummy_origin.x = X_ORIGIN_OFF - (fdf->mtrx->size->x / 2);
	dummy_origin.y = Y_ORIGIN_OFF - (fdf->mtrx->size->y / 2);
	pos.x = round(dummy_origin.x);
	pos.y = round(dummy_origin.y);
	size_aux.x = fdf->mtrx->size->x + dummy_origin.x;
	size_aux.y = fdf->mtrx->size->y + dummy_origin.y;
	//new_img->x = X_ORIGIN_OFF - (fdf->mtrx->size->x / 2);
	//new_img->y = Y_ORIGIN_OFF - (fdf->mtrx->size->y / 2);
	
	while (pos.x  <= fdf->mtrx->size->x + X_ORIGIN_OFF)
	{
		pos.y  = dummy_origin.y;
		while (pos.y <= fdf->mtrx->size->y + Y_ORIGIN_OFF)
		{
			if ((int)pos.y % 2 == 0)
				mlx_put_pixel(fdf->img, pos.x , pos.y , rgba(0));
			else
				mlx_put_pixel(fdf->img, pos.x , pos.y , rgba(0.3));
			pos.y += 1;
		}
		pos.x += 1;
	}
}

/*
t_fdf	*new_img(t_fdf *fdf)
{
	t_fdf	*new_img;

	new_img = (t_fdf *)malloc(sizeof(t_fdf));
	new_img = fdf;
	new_img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	new_img->img->instances->x = X_ORIGIN_OFF - (fdf->mtrx->size->x / 2);
	new_img->img->instances->y = Y_ORIGIN_OFF - (fdf->mtrx->size->y / 2);
	return (new_img);
}

mlx_instance_t	set_pos_new_img(t_fdf *fdf, mlx_image_t *img)
{
	t_vec2			original;
	t_vec2			dummy_origin;
	t_vec2			size_aux;
	mlx_instance_t	*new_img_ins;

	new_img_ins = fdf->img->instances;
	

	original.x = fdf->mtrx->size->x / 2;
	original.y = fdf->mtrx->size->y / 2;
	dummy_origin.x = X_ORIGIN_OFF - (fdf->mtrx->size->x / 2);
	dummy_origin.y = Y_ORIGIN_OFF - (fdf->mtrx->size->y / 2);
	fdf->img->instances->x = dummy_origin.x;
	fdf->img->instances->y = dummy_origin.y;
	size_aux.x = fdf->mtrx->size->x + dummy_origin.x;
	size_aux.y = fdf->mtrx->size->y + dummy_origin.y;
}
*/


void	print_box(t_fdf fdf, int color, int max_x, int max_y)
{
	while (fdf.img->instances->x - OFFSET <= max_x)
	{
		fdf.img->instances->y = OFFSET;
		while (fdf.img->instances->y - OFFSET <= max_y)
		{
			//draw_to_nxt_pt(&fdf);
			if (fdf.img->instances->y % 2 == 0)
				mlx_put_pixel(fdf.img, fdf.img->instances->x, 
				fdf.img->instances->y, menu_rgb(color)); 
			else
				mlx_put_pixel(fdf.img, fdf.img->instances->x, 
				fdf.img->instances->y, menu_rgb(color)); 
			fdf.img->instances->y += 1;
		}
		fdf.img->instances->x += 1;
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
