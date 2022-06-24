/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 00:05:04 by iostancu         ###   ########.fr       */
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


void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end)
{
	t_vec2	step;
	int		max;

	bresen_zoom(fdf, &start, &end);
	step.x = end.x - start.x;
	step.y = end.y - start.y;
	max = f_max(f_mod(step.x), f_mod(step.y));
	step.x /= max;
	step.y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		/* Add img offset to draw mesh in the middle of window */
		mlx_put_pixel(fdf->img, start.x + IMG_CENTER_X, start.y + IMG_CENTER_Y, BLU_CB);
		printf("steps in f_bresen x: %f, y: %f\n", step.x, step.y);
		start.x += step.x;
		start.y += step.y;
	}
}