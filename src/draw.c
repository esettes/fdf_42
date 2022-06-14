#include "fdf.h"

void	print_mesh(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= fdf->mtrx.segments.x)
	{
		y = 0;
		while (y <= fdf->mtrx.segments.y)
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

// void	print_mesh_at_origin(t_fdf *fdf)
// {
// 	t_vec2	origin;
// 	t_vec2	orig_cpy;
// 	int		distance;
// 	t_vec2		trigger;
// 	t_vec2	start;
// 	t_vec2	end;

// 	trigger.x = FALSE;
// 	distance = 15;
// 	origin.x = round(fdf->mtrx.start_draw.x);
// 	origin.y = round(fdf->mtrx.start_draw.y);
// 	orig_cpy.x = origin.x;
// 	orig_cpy.y = origin.y;
// 	printf("pos.x dummy origin: %f\n", origin.x);
// 	printf("pos.y dummy origin: %f\n", origin.y);
// 	while (origin.y  <= fdf->mtrx.size.y + Y_ORIGIN_OFF)
// 	{
// 		origin.x = orig_cpy.x;
// 		start.x = origin.x;
// 		start.y = origin.y;
// 		if (trigger.y == TRUE)
// 				draw_segment(start, end, fdf);
// 		while (origin.x <= fdf->mtrx.size.x + X_ORIGIN_OFF)
// 		{
// 			mlx_put_pixel(fdf->img, origin.x , origin.y , rgba(0.3));
// 			start.x = origin.x;
// 			end.x = origin.x += distance;
// 			end.y = origin.y;
// 			if (trigger.x == TRUE)
// 				draw_segment(start, end, fdf);
// 			origin.x += distance;
// 			trigger.x = TRUE;
// 		}
// 		origin.y += distance;
// 		trigger.y = TRUE;
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
