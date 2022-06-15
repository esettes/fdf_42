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
		draw_segment_horiz(start, end, fdf);
		start.y += fdf->mtrx.zoom;
		end.y += fdf->mtrx.zoom;
		seg_iter.y++;
	}
	start.y = round(fdf->mtrx.start_draw.y);
	end.y = start.y + fdf->mtrx.px_size.y;
	while (seg_iter.x < fdf->mtrx.segments.x)
	{
		draw_segment_vert(start, end, fdf);
		start.x += fdf->mtrx.zoom;
		end.x += fdf->mtrx.zoom;
		seg_iter.x++;
	}
}

void	draw_segment_horiz(t_vec2 start, t_vec2 end, t_fdf *fdf)
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
			mlx_put_pixel(fdf->img, x, y, rgba(0));
			y = y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			mlx_put_pixel(fdf->img, x, y, rgba(0));
			p = p + 2 * d.y;
		}
		x = x + 1;
	}
}

void	draw_segment_vert(t_vec2 start, t_vec2 end, t_fdf *fdf)
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
			mlx_put_pixel(fdf->img, x, y, rgba(0));
			//y = y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			mlx_put_pixel(fdf->img, x, y, rgba(0));
			p = p + 2 * d.y;
		}
		y = y + 1;
	}
}
