/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/29 18:51:33 by iostancu         ###   ########.fr       */
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
	coord->x = ((coord->x ) - (coord->y )) * cos(45) * 1;
	coord->y = ((coord->x) + (coord->y )) * (sin(45) * 0.5)  - (z  * 0.5);
	(void)fdf;
}


void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end)
{
	t_vec2	step;
	int		max;
	int		color;
	t_vec2	offset;
	t_depth	depth;
	t_iter	aux;

	aux.i = (int)start.x;
	aux.j = (int)start.y;
	depth.z = fdf->mtrx.mtrx[(int)start.y][(int)start.x];
	depth.z1 = fdf->mtrx.mtrx[(int)end.y][(int)end.x];
	bresen_zoom(fdf, &start, &end);
	
	offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 8);
	offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 4);
	
	//isometric(fdf, &start, &end, depth);
	iso(fdf, &start, depth.z);
	iso(fdf, &end, depth.z1);
	step.x = end.x - start.x;
	step.y = end.y - start.y;
	max = f_max(f_mod(step.x), f_mod(step.y));
	step.x /= max;
	step.y /= max;
	//printf("\n********	in f_bresen (outer while)	********\n");
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		//if (fdf->mtrx.colors[aux.i][aux.j] < 0)
		//	color = 0xff;
		//else
		color = fdf->mtrx.colors[aux.j][aux.i];
		mlx_put_pixel(fdf->img, start.x + offset.x, start.y + offset.y, color);
		start.x += step.x;
		start.y += step.y;
	}
}