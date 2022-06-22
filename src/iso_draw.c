/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:12 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/22 00:09:58 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	set_mesh_iso(t_fdf *fdf)
{
	t_vec2	iso_pos;

	iso_pos.x = get_iso_pos_x(fdf->mtrx);
	iso_pos.y = get_iso_pos_y(fdf->mtrx);
	return (iso_pos);
}

double	get_iso_pos_x(t_mtrx mtrx)
{
	t_vec2	size;
	double	pos_x;

	size.x = mtrx.segments.x / 2;
	size.y = mtrx.segments.y / 2;
	pos_x = (size.x) * cos(30) - (size.y * sin(30));
	pos_x = IMG_CENTER_X + pos_x - mtrx.px_size.x;
	return (pos_x);
}

double	get_iso_pos_y(t_mtrx mtrx)
{
	t_vec2	size;
	double	pos_y;

	size.x = mtrx.segments.x / 2;
	size.y = mtrx.segments.y / 2;
	pos_y = (size.x) * sin(30) + (size.y * cos(30));
	pos_y = IMG_CENTER_Y + pos_y - mtrx.px_size.y;
	return (pos_y);
}

void	zoom(t_fdf *fdf)
{
	fdf->mtrx.start.x *= fdf->mtrx.control.zoom;
	fdf->mtrx.start.y *= fdf->mtrx.control.zoom;
	fdf->mtrx.end.x *= fdf->mtrx.control.zoom;
	fdf->mtrx.end.y *= fdf->mtrx.control.zoom;
}

float	f_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	f_mod(float a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

void	new_view_iso_testing(t_fdf *fdf)
{
	t_vec2	coord;

	coord.y = 0;
	while (coord.y < fdf->mtrx.px_size.y)
	{
		coord.x = 0;
		while (coord.x < fdf->mtrx.px_size.x)
		{
			if (coord.x < fdf->mtrx.px_size.x - 1)
			{
				line_horiz(coord, fdf);
				f_bresen(fdf);
			}
			if (coord.y < fdf->mtrx.px_size.y - 1)
			{
				line_vert(coord, fdf);
				f_bresen(fdf);
			}
			coord.x++;
		}
		coord.y++;
	}
}

void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth dep)
{
	start->x = ((start->x - start->y) * cos(0.8));
	start->y = ((start->x + start->y) * sin(0.8) - dep.z);
	end->x = ((end->x - end->y) * cos(0.8));
	end->y = ((end->x + end->y) * sin(0.8) - dep.z1);
	(void)fdf;
}

void	line_horiz(t_vec2 coord, t_fdf *fdf)
{
	fdf->mtrx.start.x = coord.x;
	fdf->mtrx.start.y = coord.y;
	fdf->mtrx.end.x = coord.x + 1;
	fdf->mtrx.end.y = coord.y;
}

void	line_vert(t_vec2 coord, t_fdf *fdf)
{
	fdf->mtrx.start.x = coord.x;
	fdf->mtrx.start.y = coord.y;
	fdf->mtrx.end.x = coord.x;
	fdf->mtrx.end.y = coord.y + 1;
}

void	f_bresen(t_fdf *fdf)
{
	t_vec2	step;
	int		max;
	t_depth	depth;

	depth = set_depth(fdf);
	isometric(fdf, &fdf->mtrx.start, &fdf->mtrx.end, depth);
	step.x = fdf->mtrx.end.x - fdf->mtrx.start.x;
	step.y = fdf->mtrx.end.y - fdf->mtrx.start.y;
	max = f_max(f_mod(step.x), f_mod(step.y));
	step.x /= max;
	step.y /= max;
	while ((int)(fdf->mtrx.start.x - fdf->mtrx.end.x) 
		|| (int)(fdf->mtrx.start.y - fdf->mtrx.end.y))
		bresen_put_pixel(fdf, step);
}


t_depth	set_depth(t_fdf *fdf)
{
	t_depth	dep;

	dep.z = fdf->mtrx.depth[(int)fdf->mtrx.start.y][(int)fdf->mtrx.start.x] 
		* fdf->mtrx.control.height;
	dep.z1 = fdf->mtrx.depth[(int)fdf->mtrx.end.y][(int)fdf->mtrx.end.x] 
		* fdf->mtrx.control.height;
	return (dep);
}

void	bresen_put_pixel(t_fdf *fdf, t_vec2 step)
{
	mlx_put_pixel(fdf->img, fdf->mtrx.start.x,
		fdf->mtrx.start.y, rgba(0));
	fdf->mtrx.start.x += step.x;
	fdf->mtrx.start.y += step.y;
}