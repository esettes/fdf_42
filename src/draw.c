#include "fdf.h"

// void	draw_outer_segments(t_fdf *fdf)
// {
// 	t_vec2	start;
// 	t_vec2	end;
// 	t_vec2	seg_iter;

// 	seg_iter.x = 0;
// 	seg_iter.y = 0;
// 	start.x = (int)fdf->mtrx.start_draw.x;
// 	start.y = (int)fdf->mtrx.start_draw.y;
// 	end.x = (int)fdf->mtrx.end_draw.x;
// 	end.y = (int)fdf->mtrx.start_draw.y;
// 	while (seg_iter.y < fdf->mtrx.segments.y)
// 	{
// 		draw_segment_horiz(start, end, fdf);
// 		start.y += fdf->mtrx.zoom;
// 		end.y += fdf->mtrx.zoom;
// 		seg_iter.y++;
// 	}
// 	start.y = round(fdf->mtrx.start_draw.y);
// 	end.y = start.y + fdf->mtrx.px_size.y;
// 	while (seg_iter.x < fdf->mtrx.segments.x)
// 	{
// 		draw_segment_vert(start, end, fdf);
// 		start.x += fdf->mtrx.zoom;
// 		end.x += fdf->mtrx.zoom;
// 		seg_iter.x++;
// 	}
// }

void	draw_outer_segments(t_fdf *fdf)
{
	t_vec2	start;
	t_vec2	end;
	t_vec2	seg_iter;

	t_vec2	img_size;

	seg_iter.x = 0;
	seg_iter.y = 0;
	start.x = (int)fdf->mtrx.start_draw.x;
	start.y = (int)fdf->mtrx.start_draw.y;
	end.x = (int)fdf->mtrx.end_draw.x;
	end.y = (int)fdf->mtrx.start_draw.y;

	img_size.x = (int)fdf->img->width;
	img_size.y = (int)fdf->img->height;
	while (seg_iter.y < fdf->mtrx.segments.y)
	{
		draw_segment_horiz(start, end, fdf, 0);
		start.y += fdf->mtrx.zoom;
		end.y += fdf->mtrx.zoom;
		seg_iter.y++;
	}
	start.y = round(fdf->mtrx.start_draw.y);
	end.y = start.y + fdf->mtrx.px_size.y;
	while (seg_iter.x < fdf->mtrx.segments.x)
	{
		draw_segment_vert(start, end, fdf, 0);
		start.x += fdf->mtrx.zoom;
		end.x += fdf->mtrx.zoom;
		seg_iter.x++;
	}
}

void	test_draw_iso(t_fdf *fdf)
{
	t_vec2	start;
	t_vec2	end;
	t_vec2	seg_iter;
	t_vec2 aux;
	//t_vec2 endaux;

	t_vec2	img_size;

	seg_iter.x = 0;
	seg_iter.y = 0;
	
	aux.x = (IMG_CENTER_X - (int)fdf->mtrx.start_draw.x) * 0.99;
	aux.y = (IMG_CENTER_Y - (int)fdf->mtrx.start_draw.y) * 0.99;

	start.x = (int)fdf->mtrx.start_draw.x + aux.x;
	start.y = (int)fdf->mtrx.start_draw.y;


	end.x = (int)fdf->mtrx.end_draw.x + aux.x;
	end.y = (int)fdf->mtrx.start_draw.y + aux.y;

	img_size.x = (int)fdf->img->width;
	img_size.y = (int)fdf->img->height;
	while (seg_iter.y < fdf->mtrx.segments.y)
	{
		draw_segment_horiz(start, end, fdf, 0);
		start.x -= fdf->mtrx.zoom * cos (45) * 1.9;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
		start.y += fdf->mtrx.zoom * sin(45) * 0.6;
		end.x -= fdf->mtrx.zoom * cos (45) * 1.9;
		end.y += fdf->mtrx.zoom * sin (45) * 0.6;
		
		seg_iter.y++;
	}
	
	start.x = (int)fdf->mtrx.start_draw.x;
	start.y = (int)fdf->mtrx.start_draw.y;
	end.x = (int)fdf->mtrx.end_draw.x;
	end.y = (int)fdf->mtrx.start_draw.y;
	start.y = round(fdf->mtrx.start_draw.y);
	end.y = start.y + fdf->mtrx.px_size.y;
	while (seg_iter.x < fdf->mtrx.segments.x)
	{
		draw_segment_vert(start, end, fdf, 0.6);
		start.x += fdf->mtrx.zoom;
		end.x += fdf->mtrx.zoom;
		seg_iter.x++;
	}


	// t_vec2	start;
	// t_vec2	end;
	// t_vec2	seg_iter;

	// t_vec2	img_size;
	// t_vec2	size;
	// t_vec2	pos;

	// seg_iter.x = 0;
	// seg_iter.y = 0;
	
	// size.x = fdf->mtrx.segments.x / 2;
	// size.y = fdf->mtrx.segments.y / 2;
	// pos.x = (size.x) * cos(30) - (size.y * sin(30));
	// pos.x = IMG_CENTER_X + pos.x - fdf->mtrx.px_size.x;
	// pos.y = (size.x) * sin(30) + (size.y * cos(30));
	// pos.y = IMG_CENTER_Y + pos.y - fdf->mtrx.px_size.y;

	// //start = set_mesh_iso(fdf);
	// start.x = (int)fdf->mtrx.start_draw.x;
	// start.y = (int)fdf->mtrx.start_draw.y;
	// //end = set_mesh_iso(fdf);
	// end.x += fdf->mtrx.px_size.x;
	// end.y += fdf->mtrx.px_size.y ;


	// img_size.x = (int)fdf->img->width;
	// img_size.y = (int)fdf->img->height;
	// while (seg_iter.y < fdf->mtrx.segments.y)
	// {
	// 	draw_segment_horiz(start, end, fdf, 0);
	// 	start.x -= (size.x) * cos(30);
	// 	start.y += fdf->mtrx.zoom / sin (30);
	// 	end.x -= (size.y * cos(30));
	// 	end.y += fdf->mtrx.zoom / sin (30);
	// 	seg_iter.y++;
	// }
	// start.y = round(fdf->mtrx.start_draw.y);
	// end.y = start.y + fdf->mtrx.px_size.y;
	// while (seg_iter.x < fdf->mtrx.segments.x)
	// {
	// 	draw_segment_vert(start, end, fdf, 0.6);
	// 	start.x += fdf->mtrx.zoom ;
	// 	//start.y += fdf->mtrx.zoom;
	// 	end.x += fdf->mtrx.zoom;
	// 	//end.y += fdf->mtrx.zoom ;
	// 	seg_iter.x++;
	// }



	// while (seg_iter.y < fdf->mtrx.segments.y)
	// {
	// 	/* Dejar coordenadas tal cual salen de set_mesh_iso
	// 	Luego "partir" por la mitad el cuadrado, y hacer un corte desde la esquina derecha hasta
	// 	el vertice donde se corta la parte de abajo.
	// 	lo que sobra, colocarlo por orden en la esquina superior izquierda, creando así la perspectiva*/
	// 	//new_start.x += (fdf->mtrx.zoom ) * sin(30);// - (fdf->mtrx.segments.y / 2 * sin(30));
	// 	//new_start.y += (fdf->mtrx.zoom);// * cos(30);
	// 	//new_end.x += (fdf->mtrx.zoom ) * sin(30);
	// 	//new_end.y += (fdf->mtrx.zoom);// * cos(30);
	// 	new_start


	// 	draw_segment_horiz(new_start, new_end, fdf, 0.6);
	// 	seg_iter.y++;
	// }
	// new_start = set_mesh_iso(fdf);
	// new_start.y = round(fdf->mtrx.start_draw.y);
	// new_end.y = new_start.y + fdf->mtrx.px_size.y;
	// while (seg_iter.x < fdf->mtrx.segments.x)
	// {
	// 	draw_segment_vert(new_start, new_end, fdf, 0);
	// 	new_start.x += fdf->mtrx.zoom * sin(30);
	// 	new_start.y += fdf->mtrx.zoom * cos(30);
	// 	new_end.x += fdf->mtrx.zoom * sin(30);
		
	// 	seg_iter.x++;
	// }
}

void	draw_segment_horiz(t_vec2 start, t_vec2 end, t_fdf *fdf, double color)
{
	int p, x, y;
	t_vec2	d;

	d.x = end.x - start.x;
	d.y = end.y - start.y;

	x = start.x;
	y = start.y;

	p = 2 * d.y - d.x;
	while(x < end.x)
	{
		if(p >= 0)
		{
			mlx_put_pixel(fdf->img, x, y, rgba(color));
			y = y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			mlx_put_pixel(fdf->img, x, y, rgba(color));
			p = p + 2 * d.y;
		}
		x = x + 1;
	}
}

void	draw_segment_vert(t_vec2 start, t_vec2 end, t_fdf *fdf, double color)
{
	int p, x, y;
	t_vec2	d;

	d.x = end.x - start.x;
	d.y = end.y - start.y;
	x = start.x;
	y = start.y;
	p = 2 * d.y - d.x;
	while(y < end.y)
	{
		if(p >= 0)
		{
			mlx_put_pixel(fdf->img, x, y, rgba(color));
			//y = y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			mlx_put_pixel(fdf->img, x, y, rgba(color));
			p = p + 2 * d.y;
		}
		y = y + 1;
	}
}

void	draw_segment_negative(t_vec2 start, t_vec2 end, t_fdf *fdf, double color)
{
	int p, x, y;
	t_vec2	d;

	d.x = end.x - start.x;
	d.y = end.y - start.y;
	x = start.x;
	y = start.y;
	p = 2 * d.y - d.x;
	while(y < end.y)
	{
		if(p >= 0)
		{
			mlx_put_pixel(fdf->img, x, y, rgba(color));
			//y = y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			mlx_put_pixel(fdf->img, x, y, rgba(color));
			p = p + 2 * d.y;
		}
		y = y + 1;
	}
}
