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
	start.x = (int)fdf->mtrx.start.x;
	start.y = (int)fdf->mtrx.start.y;
	end.x = (int)fdf->mtrx.end.x;
	end.y = (int)fdf->mtrx.start.y;

	while (seg_iter.y < fdf->mtrx.segments.y)
	{
		draw_segment_to_right(start, end, fdf, 0);
		start.y += fdf->mtrx.zoom;
		end.y += fdf->mtrx.zoom;
		seg_iter.y++;
	}
	start.y = round(fdf->mtrx.start.y);
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
	t_vec2	seg_iter;
	t_vec2 	aux;
	t_vec2	zoom_iter;
	t_vec2	iso_dist;
	t_mtrx	m;
	int		newline;
	t_vec2	aux_start;

	m = fdf->mtrx;
	seg_iter.x = 0;
	seg_iter.y = 0;
	zoom_iter.x = m.px_size.y / m.segments.x;
	zoom_iter.y = m.px_size.x / m.segments.y;
	iso_dist.x = 2;
	iso_dist.y = 0.5;
	newline = TRUE;
	
	
	aux.x = (IMG_CENTER_X - m.start.x) * 1;
	aux.y = (IMG_CENTER_Y - m.start.y) * 1;

	m.start.x += aux.x;


	m.line.v_end.x = m.start.x + m.zoom + aux.x;
	m.line.v_end.y = m.start.y + aux.y;

	m.line.h_end.x = m.start.x + m.zoom + aux.x;
	m.line.h_end.y = m.start.y + aux.y;

	/* Hay que determinar un end para cada línea, ya no sirve el antiguo end */
	while(seg_iter.y < m.segments.y)
	{
		seg_iter.x = 0;
 		while (seg_iter.x < m.segments.x)
		{
			if (seg_iter.x < m.segments.x - 1) // segments.x = vertical lines
 			{
				draw_segment_to_left(m.start, m.line.v_end, fdf, 0);
				if (newline == TRUE)
				{
					newline = FALSE;
					aux_start.x = m.line.v_end.x;
					aux_start.y = m.line.v_end.y;
				}
				m.line.v_end.x += zoom_iter.y * cos (45) * iso_dist.x;
				m.line.v_end.y += zoom_iter.x * sin (45) * iso_dist.y;
			}
			if (seg_iter.y < m.segments.y - 1)
 			{
				draw_segment_to_right(m.start, m.line.h_end, fdf, 4);
				m.line.h_end.x += zoom_iter.y * cos (45) * iso_dist.x;
				m.line.h_end.y += zoom_iter.x * sin (45) * iso_dist.y;
			}
			// el último end es el nuevo start
			m.start.x = m.line.h_end.x;
			m.start.y = m.line.h_end.y;
			seg_iter.x += 1;
		}
		newline = TRUE;
		// en nueva línea, start es = auxiliar
		m.start.x = aux_start.x;
		m.start.y = aux_start.y;
		seg_iter.y += 1;
	}


/*	
	while(seg_iter.y < fdf->mtrx.segments.y)
//	while (seg_iter.y <= fdf->mtrx.px_size.y)
	{
		if (seg_iter.y < 2)
			draw_segment_to_right(start, end, fdf, 4);
		if (seg_iter.y >= 2)
			draw_segment_to_right(start, end, fdf, 0);
		start.x -= zoom_iter.y * cos (45) * iso_dist.x;// + fdf->mtrx.px_size.x; // * (fdf->mtrx.px_size.x * cos(30));
		start.y += zoom_iter.x * sin(45) * iso_dist.y;
		end.x -= zoom_iter.y * cos (45) * iso_dist.x;
		end.y += zoom_iter.x * sin (45) * iso_dist.y;
		
		seg_iter.y++;
	}
	printf("\nin test_view_iso,last start.x and start.y: %f, %f\n", start.x, start.y);
	start.x = fdf->mtrx.start.x + aux.x;
	start.y = fdf->mtrx.start.y;
	end.x = fdf->mtrx.end.x + aux.x;// - (zoom_iter.y * sin (45) * iso_dist.y);
	end.y = fdf->mtrx.start.y + aux.y;//  - (zoom_iter.x * cos (45) * iso_dist.x);
	printf("\nin test_view_iso, first end.x and end.y: %f, %f\n", end.x, end.y);
	while (seg_iter.x < fdf->mtrx.segments.x)
//	while(seg_iter.x <= fdf->mtrx.px_size.x)
	{
		if (seg_iter.x < 2)
			draw_segment_to_left(start, end, fdf, 4);
		if (seg_iter.x >= 2)
			draw_segment_to_left(start, end, fdf, 1);
		start.x += zoom_iter.x * cos (45) * iso_dist.x;// + fdf->mtrx.px_size.x; // * (fdf->mtrx.px_size.x * cos(30));
		start.y += zoom_iter.y * sin(45) * iso_dist.y;
		end.x += zoom_iter.x * cos (45) * iso_dist.x;
		end.y += zoom_iter.y * sin (45) * iso_dist.y;
		seg_iter.x++;
	}*/
}

// void	test_view_iso(t_fdf *fdf)
// {
// 	t_vec2	start;
// 	t_vec2	start_right;
// 	t_vec2	start_left;
// 	t_vec2	end;
// 	t_vec2	seg_iter;
// 	t_vec2 	aux;
// 	t_vec2	end_right;
// 	t_vec2	end_left;

// 	seg_iter.x = 0;
// 	seg_iter.y = 0;
	
// 	aux.x = (IMG_CENTER_X - fdf->mtrx.start_draw.x) * 1;
// 	aux.y = (IMG_CENTER_Y - fdf->mtrx.start_draw.y) * 1;

// 	start.x = fdf->mtrx.start_draw.x + aux.x;
// 	start.y = fdf->mtrx.start_draw.y;
	
// 	start_right.x = fdf->mtrx.start_draw.x + aux.x;
// 	start_right.y = fdf->mtrx.start_draw.y;

// 	start_left.x = fdf->mtrx.start_draw.x + aux.x;
// 	start_left.y = fdf->mtrx.start_draw.y;
	

// 	end.x = fdf->mtrx.end_draw.x + aux.x;

// 	end.y = fdf->mtrx.start_draw.y + aux.y;

// 	end_right.x = fdf->mtrx.end_draw.x + aux.x;
// 	end_right.y = fdf->mtrx.start_draw.y  + aux.y;

// 	end_left.x = fdf->mtrx.end_draw.x + aux.x;
// 	end_left.y = fdf->mtrx.start_draw.y + aux.y;

	

// 	while (seg_iter.y < fdf->mtrx.segments.y)
// 	{
// 		seg_iter.x = 0;
// 		while (seg_iter.x < fdf->mtrx.segments.x)
// 		{
// 			if (seg_iter.y < fdf->mtrx.segments.y - 1)
// 			{
// 				draw_segment_to_right(start, end_right, fdf, 0);
// 				end_right.x -= fdf->mtrx.zoom * cos (45) * 1.8999999999;
// 				end_right.y = end.y;
// 			}
// 			if (seg_iter.x < fdf->mtrx.segments.x - 1)
// 			{
// 				draw_segment_to_left(start, end_left, fdf, 4);
// 				end_left.x += fdf->mtrx.zoom * cos (45) * 1.8999999999;
// 				end_left.y = end.y;
// 			}
// 			start.x = end_right.x;
// 			start.y = end.y; //+= fdf->mtrx.zoom * sin(45) * 0.5999999999;
// 			end.y += fdf->mtrx.zoom * sin (45) * 0.5999999999;
// 			seg_iter.x++;
// 		}
// 		seg_iter.y++;
// 	}
// }


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
			// if (count < 20)
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(color));
			// else
			// 	mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(0));
			coord.y = coord.y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			// if (count < 50)
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(color));
			// else
			// 	mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(0));
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
			//if (count < 20)
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(color));
			// else
			// 	mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(1));
			coord.y = coord.y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
			//if (count < 20)
				mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(color));
			// else
			// 	mlx_put_pixel(fdf->img, coord.x, coord.y, rgba(1));
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
	
	aux.x = (IMG_CENTER_X - (int)fdf->mtrx.start.x) * 1;
	aux.y = (IMG_CENTER_Y - (int)fdf->mtrx.start.y) * 1;

	start.x = (int)fdf->mtrx.start.x + aux.x;
	start.y = (int)fdf->mtrx.start.y;

	end.x = (int)fdf->mtrx.end.x + aux.x;
	end.y = (int)fdf->mtrx.start.y + aux.y;
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

	offset.x = (IMG_CENTER_X - (int)fdf->mtrx.start.x) * 0.99;
	offset.y = (IMG_CENTER_Y - (int)fdf->mtrx.start.y) * 0.99;
	start->x = (int)fdf->mtrx.start.x + offset.x;
	start->y = (int)fdf->mtrx.start.y;
	end->x = (int)fdf->mtrx.end.x + offset.x;
	end->y = (int)fdf->mtrx.start.y + offset.y;
}
