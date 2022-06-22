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

	seg_iter.x = 0;
	seg_iter.y = 0;
	start.x = (int)fdf->mtrx.start_draw.x;
	start.y = (int)fdf->mtrx.start_draw.y;
	end.x = (int)fdf->mtrx.end_draw.x;
	end.y = (int)fdf->mtrx.start_draw.y;

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
		draw_segment_negative(start, end, fdf, 0);
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
	t_vec2 	aux;
	// t_vec2	save;
//	t_vec2	aux_vert;

	seg_iter.x = 0;
	seg_iter.y = 0;
	
	aux.x = (IMG_CENTER_X - (int)fdf->mtrx.start_draw.x) * 0.99;
	aux.y = (IMG_CENTER_Y - (int)fdf->mtrx.start_draw.y) * 0.99;

	start.x = (int)fdf->mtrx.start_draw.x + aux.x;
	start.y = (int)fdf->mtrx.start_draw.y;

	// save.x = start.x;
	// save.y = start.y;
	end.x = (int)fdf->mtrx.end_draw.x + aux.x;
	end.y = (int)fdf->mtrx.start_draw.y + aux.y;

	while (seg_iter.y < fdf->mtrx.segments.y)
	{
		if (seg_iter.y < 2)
			draw_segment_horiz(start, end, fdf, 0.4);
		if (seg_iter.y >= 2)
			draw_segment_horiz(start, end, fdf, 0);
		start.x -= fdf->mtrx.zoom * cos(45) * 1.9;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
		start.y += fdf->mtrx.zoom * sin(45) * 0.6;
		end.x -= fdf->mtrx.zoom * cos(45) * 1.9;
		end.y += fdf->mtrx.zoom * sin(45) * 0.6;
		
		seg_iter.y++;
	}
//	aux_vert.x = (IMG_CENTER_X - (int)fdf->mtrx.end_draw.x) * 0.99;
//	aux_vert.y = (IMG_CENTER_Y - (int)fdf->mtrx.start_draw.y) * 0.99;

	//start.x = (int)fdf->mtrx.start_draw.x + aux.x;
	//start.y = (int)fdf->mtrx.start_draw.y ;
	// end.x = (int)fdf->mtrx.end_draw.x - aux_vert.x;
	// end.y = (int)fdf->mtrx.start_draw.y + aux_vert.y;
	end.x = (int)fdf->mtrx.start_draw.x + aux.x;
	end.y = (int)fdf->mtrx.start_draw.y - aux.y;
	while (seg_iter.x < fdf->mtrx.segments.x)
	{
		if (seg_iter.x < 2)
			draw_segment_vert(start, end, fdf, 0.4);
		if (seg_iter.x >= 2)
			draw_segment_vert(start, end, fdf, 0.6);
		start.x += fdf->mtrx.zoom * cos (45) * 1.9;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
		start.y += fdf->mtrx.zoom * sin(45) * 0.6;
		end.x += fdf->mtrx.zoom * cos (45) * 1.9;
		end.y -= fdf->mtrx.zoom * sin (45) * 0.6;
		seg_iter.x++;
	}

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
	p = 2 * d.x - d.y;
	while(x < end.x)
	{
		if(p >= 0)
		{
			mlx_put_pixel(fdf->img, x, y, rgba(color));
			y = y - 1;
			p = p + 2 * d.x - 2 * d.y;
		}
		else
		{
			mlx_put_pixel(fdf->img, x, y, rgba(color));
			p = p + 2 * d.x;
		}
		x = x + 1;
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
