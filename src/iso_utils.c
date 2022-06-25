/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 04:22:03 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresen_zoom(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x *= fdf->control.zoom;
	start->y *= fdf->control.zoom;
	end->x *= fdf->control.zoom;
	end->y *= fdf->control.zoom;
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

void	line_horiz(t_vec2 coord, t_fdf *fdf)
{
	fdf->mtrx.start.x += coord.x;
	fdf->mtrx.start.y += coord.y;
	fdf->mtrx.end.x += coord.x + 1;
	fdf->mtrx.end.y += coord.y;
    fdf->mtrx.current.x += coord.x;
	fdf->mtrx.current.y += coord.y;
	fdf->mtrx.next.x += coord.x + 1;
	fdf->mtrx.next.y += coord.y;
}

void	line_vert(t_vec2 coord, t_fdf *fdf)
{
	fdf->mtrx.start.x += coord.x;
	fdf->mtrx.start.y += coord.y;
    fdf->mtrx.end.x += coord.x;
	fdf->mtrx.end.y += coord.y + 1;
    fdf->mtrx.current.x += coord.x;
	fdf->mtrx.current.y += coord.y;
	fdf->mtrx.next.x += coord.x;
	fdf->mtrx.next.y += coord.y + 1;
}

void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)//, t_vec2 *end, t_depth dep)
{
	start->x = (start->x - start->y) * cos(0.8);
	start->y = (start->x + start->y) * sin(0.8) - depth.z;
	end->x = (end->x - end->y) * cos(0.8);
	end->y = (end->x + end->y) * sin(0.8) - depth.z;
	(void)fdf;
}

void	iso(t_fdf *fdf, t_vec2 *coord, int z)
{
	t_vec2	zoom_iter;
	
	zoom_iter.x = fdf->mtrx.px_size.y / fdf->mtrx.vertices.x;
	zoom_iter.y = fdf->mtrx.px_size.x / fdf->mtrx.vertices.y;
	
	coord->x = ((coord->x ) - (coord->y )) * cos(45) * 1;
	coord->y = ((coord->x) + (coord->y )) * (sin(45) * 0.5)  - (z  * 0.5);
}

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end)
{
	t_vec2	step;
	int		max;
	t_vec2	offset;
	t_depth	depth;
	int		**z_mesh;
	int		color;

	z_mesh = fdf->mtrx.mtrx;
	
	depth.z = z_mesh[(int)start.y][(int)start.x];
	depth.z1 = z_mesh[(int)end.y][(int)end.x];
	bresen_zoom(fdf, &start, &end);
	if (depth.z > 11)
		color = 0x718DAEFF;
	else if (depth.z > 9)
		color = 0x4D98AEFF;
	else if (depth.z > 7)
		color = 0x1F4079FF;
	else if (depth.z > 5)
		color = 0x183646FF;
	else if (depth.z >= 1)
		color = 0x0E1C24FF;
	else
		color = 0x00000012;
	
	offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 2);
	offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 2);
	
	
	//isometric(fdf, &start, &end, depth);
	iso(fdf, &start, depth.z);
	iso(fdf, &end, depth.z1);
	step.x = end.x - start.x;
	step.y = end.y - start.y;
	max = f_max(f_mod(step.x), f_mod(step.y));
	step.x /= max;
	step.y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		mlx_put_pixel(fdf->img, start.x + offset.x , start.y + offset.y, color);
		start.x += step.x;
		start.y += step.y;
	}
}