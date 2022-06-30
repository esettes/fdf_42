/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/30 20:23:46 by iostancu         ###   ########.fr       */
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
	start->x = (start->x - start->y) * cos(45) * 1;
	start->y = (start->x + start->y) * (sin(45) * 0.5)  - (depth.z  * 0.5);
	end->x = (end->x - end->y) * cos(45) * 1;
	end->y = (end->x + end->y) * (sin(45) * 0.5)  - (depth.z1  * 0.5);
	(void)fdf;
}

void	iso(t_fdf *fdf, t_vec2 *coord, int z)
{
	coord->x = ((coord->x ) - (coord->y )) * cos(45) * 1;
	coord->y = ((coord->x) + (coord->y )) * (sin(45) * 0.5)  - (z  * 0.5);
	(void)fdf;
}


void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end, int direction)
{
	t_vec2	step;
	float step1;
	float step2;
	int		max;
	int		color;
	t_vec2	offset;
	t_depth	depth;
	t_iter	curr;
	t_vec2	coord;
	//double	percent;
	int		p;

	curr.i = (int)start.x;
	curr.j = (int)start.y;
	coord.x = 0;
	coord.y = 0;
	
	depth.z = fdf->mtrx.mtrx[(int)start.y][(int)start.x];
	depth.z1 = fdf->mtrx.mtrx[(int)end.y][(int)end.x];
	bresen_zoom(fdf, &start, &end);
	
	offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 8);
	offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 4);
	
	isometric(fdf, &start, &end, depth);
	//iso(fdf, &start, depth.z);
	//iso(fdf, &end, depth.z1);
	coord.x = start.x;
	coord.y = start.y;
	step.x = (float)(end.x - start.x);
	step.y = (float)(end.y - start.y);
	
	step1 = (float)(end.x - start.x);
	step2 = (float)(end.y - start.y);

	
	
	max = f_max(f_mod(step.x), f_mod(step.y));
	step.x /= max;
	step.y /= max;
	//printf("\n********	in f_bresen (outer while)	********\n");
	if (direction == 0)
	{
		p = 2 * step2 - step1;
		while (coord.x < end.x)// && (int)coord.x - end.x)
		{
			color = fdf->mtrx.colors[curr.j][curr.i];
			if (p > 0)
			{
				mlx_put_pixel(fdf->img, coord.x + offset.x, coord.y + offset.y, color);
				coord.y = coord.y + 1;
				p = p + 2 * step2 - 2 * step1;
			}
			else
			{
				mlx_put_pixel(fdf->img, coord.x + offset.x, coord.y + offset.y, color);
				p = p + 2 * step2;
			}
			coord.x = coord.x + 1;
		}
	}
	else
	{
		p = 2 * step1 - step2;
		while (coord.x > end.x)// && coord.y - end.y)
		{
			color = fdf->mtrx.colors[curr.j][curr.i];
			if (p > 0)
			{
				mlx_put_pixel(fdf->img, coord.x + offset.x, coord.y + offset.y, color);
				coord.y = coord.y + 1;
				p = p + 2 * step2 - 2 * step1;
			}
			else
			{
				mlx_put_pixel(fdf->img, coord.x + offset.x, coord.y + offset.y, color);
				p = p + 2 * step2;
			}
			coord.x = coord.x - 1;
		}
	}
}

void	f_bresen_left(t_fdf *fdf, t_vec2 start, t_vec2 end)// t_vec2 before)
{
	t_vec2	step;
	int		max;
	int		color;
	t_vec2	offset;
	t_depth	depth;
	t_iter	curr;
	//double	percent;
	int		p;

	curr.i = (int)start.x;
	curr.j = (int)start.y;
	depth.z = fdf->mtrx.mtrx[(int)start.y][(int)start.x];
	depth.z1 = fdf->mtrx.mtrx[(int)end.y][(int)end.x];
	bresen_zoom(fdf, &start, &end);
	
	offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 8);
	offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 4);
	
	isometric(fdf, &start, &end, depth);
	//iso(fdf, &start, depth.z);
	//iso(fdf, &end, depth.z1);
	step.x = end.x - start.x;
	step.y = end.y - start.y;

	p = 2 * step.x - step.y;
	
	max = f_max(f_mod(step.x), f_mod(step.y));
	step.x /= max;
	step.y /= max;
	//printf("\n********	in f_bresen (outer while)	********\n");
	while ((int)(start.y - end.y))
	{
		//if (fdf->mtrx.colors[aux.i][aux.j] < 0)
		//	color = 0xff;
		//else
		
		/*if (fabs(step.x)  + -fabs(step.y) > 0)
			percent = ft_percent(curr.j, end.y, start.y);
		else
			percent = ft_percent(curr.i, end.x, start.x);
		
		color = ft_gradient(fdf->mtrx.colors[curr.j][curr.i], 
			fdf->mtrx.colors[(int)end.y][(int)end.x], percent);*/
		color = fdf->mtrx.colors[curr.j][curr.i];
		//printf("\ncolor: %i ********\n", color);
		if (p > 0)
		{
			mlx_put_pixel(fdf->img, start.x + offset.x, start.y + offset.y, color);
			start.y += 1;
			p = p + 2 * step.y - 2 * step.x;
		}
		else
		{
			mlx_put_pixel(fdf->img, start.x + offset.x, start.y + offset.y, color);
			p = p + 2 * step.y;
		}
		//start.x += step.x;
		start.y += 1;
	}
}