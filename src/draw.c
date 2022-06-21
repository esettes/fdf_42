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

void	view_on_top(t_fdf *fdf)
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
		draw_segment_to_right(start, end, fdf, 0);
		start.y += fdf->mtrx.zoom;
		end.y += fdf->mtrx.zoom;
		seg_iter.y++;
	}
	start.y = round(fdf->mtrx.start_draw.y);
	end.y = start.y + fdf->mtrx.px_size.y;
	while (seg_iter.x < fdf->mtrx.segments.x)
	{
		draw_segment_to_left(start, end, fdf, 0);
		start.x += fdf->mtrx.zoom;
		end.x += fdf->mtrx.zoom;
		seg_iter.x++;
	}
}

void	test_view_iso(t_fdf *fdf)
{
	t_vec2	start;
	t_vec2	end;
	t_vec2	seg_iter;
	t_vec2 	aux;

	seg_iter.x = 0;
	seg_iter.y = 0;
	
	aux.x = (IMG_CENTER_X - fdf->mtrx.start_draw.x) * 1;
	aux.y = (IMG_CENTER_Y - fdf->mtrx.start_draw.y) * 1;

	start.x = fdf->mtrx.start_draw.x + aux.x;
	start.y = fdf->mtrx.start_draw.y;
	end.x = fdf->mtrx.end_draw.x + aux.x;
	end.y = fdf->mtrx.start_draw.y + aux.y;

	while (seg_iter.y <= fdf->mtrx.segments.y)
	{
		if (seg_iter.y < 2)
			draw_segment_to_right(start, end, fdf, 4);
		if (seg_iter.y >= 2)
			draw_segment_to_right(start, end, fdf, 0);
		start.x -= fdf->mtrx.zoom * cos (45) * 1.8999999999;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
		start.y += fdf->mtrx.zoom * sin(45) * 0.5999999999;
		end.x -= fdf->mtrx.zoom * cos (45) * 1.8999999999;
		end.y += fdf->mtrx.zoom * sin (45) * 0.5999999999;
		
		seg_iter.y++;
	}
	
	start.x = fdf->mtrx.start_draw.x + aux.x;
	start.y = fdf->mtrx.start_draw.y;
	end.x = fdf->mtrx.end_draw.x + aux.x;
	end.y = fdf->mtrx.start_draw.y + aux.y;
	
	while (seg_iter.x <= fdf->mtrx.segments.x)
	{
		if (seg_iter.x < 2)
			draw_segment_to_left(start, end, fdf, 4);
		if (seg_iter.x >= 2)
			draw_segment_to_left(start, end, fdf, 1);
		start.x += fdf->mtrx.zoom * cos (45) * 1.8999999999;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
		start.y += fdf->mtrx.zoom * sin(45) * 0.5999999999;
		end.x += fdf->mtrx.zoom * cos (45) * 1.8999999999;
		end.y += fdf->mtrx.zoom * sin (45) * 0.5999999999;
		seg_iter.x++;
	} 
}

// void	test_view_iso(t_fdf *fdf)
// {
// 	t_vec2	start;
// 	t_vec2	end;
// 	t_vec2	seg_iter;
// 	t_vec2 	aux;

	
// 	seg_iter.y = 0;
	
// 	aux.x = (IMG_CENTER_X - (int)fdf->mtrx.start_draw.x) * 1;
// 	aux.y = (IMG_CENTER_Y - (int)fdf->mtrx.start_draw.y) * 1;

// 	start.x = (int)fdf->mtrx.start_draw.x + aux.x;
// 	start.y = (int)fdf->mtrx.start_draw.y;

// 	end.x = (int)fdf->mtrx.end_draw.x + aux.x;
// 	end.y = (int)fdf->mtrx.start_draw.y + aux.y;

// 	while (seg_iter.y <= fdf->mtrx.segments.y)
// 	{
// 		seg_iter.x = 0;
// 		while (seg_iter.x <= fdf->mtrx.segments.x)
// 		{
// 			if (seg_iter.x < fdf->mtrx.segments.x - 1)
// 			{
// 				if (seg_iter.y < 2)
// 					draw_segment_to_right(start, end, fdf, 0.4);
// 				if (seg_iter.y >= 2)
// 					draw_segment_to_right(start, end, fdf, 0);
// 				start.x -= fdf->mtrx.zoom * cos (45) * 2;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
// 				start.y += fdf->mtrx.zoom * sin(45) * 0.5;
// 				end.x -= fdf->mtrx.zoom * cos (45) * 2;
// 				end.y += fdf->mtrx.zoom * sin (45) * 0.5;
// 			}
		
// 			end.x = (int)fdf->mtrx.start_draw.x + aux.x;
// 			end.y = (int)fdf->mtrx.start_draw.y * sin(45);
// 			while (seg_iter.x <= fdf->mtrx.segments.x)
// 			{
// 				if (seg_iter.x < 2)
// 					draw_segment_to_left(start, end, fdf, 0.4);
// 				if (seg_iter.x >= 2)
// 					draw_segment_to_left(start, end, fdf, 0.6);
// 				start.x += fdf->mtrx.zoom * cos (45) * 2;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
// 				start.y += fdf->mtrx.zoom * sin(45) * 0.5;
// 				end.x += fdf->mtrx.zoom * cos (45) * 2;
// 				end.y += fdf->mtrx.zoom * sin (45) * 0.5;
// 				seg_iter.x++;
// 			}
// 		}
// 	}
//}

void	draw_segment_to_right(t_vec2 start, t_vec2 end, t_fdf *fdf, float color)
{
	int		p;
	int		count;
	t_vec2	coord;
	t_vec2	d;

	d.x = end.x - start.x;
	d.y = end.y - start.y;
	coord.x = start.x;
	coord.y = start.y;
	p = 2 * d.y - d.x;
	count = 0;
	while(coord.x < end.x)
	{
		if(p > 0)
		{
			count++;
			if (count < 20)
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(color));
			else
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(0));
			coord.y = coord.y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			if (count < 50)
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(color));
			else
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(0));
			p = p + 2 * d.y;
		}
		coord.x = coord.x + 1;
	}
}

void	draw_segment_to_left(t_vec2 start, t_vec2 end, t_fdf *fdf, float color)
{
	int		p;
	int		count;
	t_vec2	coord;
	t_vec2	d;

	d.x = end.x - start.x;
	d.y = end.y - start.y;
	coord.x = start.x;
	coord.y = start.y;
	p = 2 * d.x - d.y;
	count = 0;
	while(coord.y < end.y)
	{
		count++;
		if(p > 0)
		{
			if (count < 20)
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(color));
			else
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(1));
			coord.y = coord.y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			if (count < 20)
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(color));
			else
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(1));
			p = p + 2 * d.y;
		}
		coord.x = coord.x - 1;
	}
}

void	new_view_iso(t_fdf *fdf)
{
	t_vec2	start;
	t_vec2	end;
	t_vec2	seg_iter;

	seg_iter.y = 0;
	set_start_to_print_iso(fdf, &start, &end);
	t_vec2 	aux;

	seg_iter.x = 0;
	seg_iter.y = 0;
	
	aux.x = (IMG_CENTER_X - (int)fdf->mtrx.start_draw.x) * 1;
	aux.y = (IMG_CENTER_Y - (int)fdf->mtrx.start_draw.y) * 1;

	start.x = (int)fdf->mtrx.start_draw.x + aux.x;
	start.y = (int)fdf->mtrx.start_draw.y;

	end.x = (int)fdf->mtrx.end_draw.x + aux.x;
	end.y = (int)fdf->mtrx.start_draw.y + aux.y;
	while (seg_iter.y < fdf->mtrx.segments.y)
	{
		seg_iter.x = 0;
		while (seg_iter.x < fdf->mtrx.segments.x)
		{
			/* Draw bresen line with the size of zoom*/
			if (seg_iter.x < fdf->mtrx.segments.x - 1)
			{
				if (seg_iter.x < 2)
					draw_segment_to_left(start, end, fdf, 4);
				if (seg_iter.x >= 2)
					draw_segment_to_left(start, end, fdf, 6);
				start.x += fdf->mtrx.zoom * cos (45) * 2;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
				start.y += fdf->mtrx.zoom * sin(45) * 0.5;
				end.x += fdf->mtrx.zoom * cos (45) * 2;
				end.y += fdf->mtrx.zoom * sin (45) * 0.5;
			}
			if (seg_iter.y < fdf->mtrx.segments.y - 1)
			{
				if (seg_iter.y < 2)
					draw_segment_to_right(start, end, fdf, 4);
				if (seg_iter.y >= 2)
					draw_segment_to_right(start, end, fdf, 0);
				start.x -= fdf->mtrx.zoom * cos (45) * 2;// + fdf->mtrx.px_size.x; //* (fdf->mtrx.px_size.x * cos(30));
				start.y += fdf->mtrx.zoom * sin(45) * 0.5;
				end.x -= fdf->mtrx.zoom * cos (45) * 2;
				end.y += fdf->mtrx.zoom * sin (45) * 0.5;
			}
			seg_iter.x++;
		}
		seg_iter.y++;
	}
}

void	set_start_to_print_iso(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	t_vec2	offset;

	offset.x = (IMG_CENTER_X - (int)fdf->mtrx.start_draw.x) * 0.99;
	offset.y = (IMG_CENTER_Y - (int)fdf->mtrx.start_draw.y) * 0.99;
	start->x = (int)fdf->mtrx.start_draw.x + offset.x;
	start->y = (int)fdf->mtrx.start_draw.y;
	end->x = (int)fdf->mtrx.end_draw.x + offset.x;
	end->y = (int)fdf->mtrx.start_draw.y + offset.y;
}