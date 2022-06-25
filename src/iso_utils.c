/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 02:52:26 by iostancu         ###   ########.fr       */
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
	t_vec2	offset;
	t_depth	depth;
	int		**z_mesh;
	int		color;

	z_mesh = fdf->mtrx.mtrx;
	
	depth.z = z_mesh[(int)start.y][(int)start.x];
	printf("mtrx[%d][%d] value: %d\n", (int)start.y, (int)start.x, fdf->mtrx.mtrx[(int)start.y][(int)start.x]);
	bresen_zoom(fdf, &start, &end);
	//depth.z1 = fdf->mtrx.mtrx[(int)end.y][(int)end.x];
	//color = 0x00000000;
	if (depth.z > 0)
		color = BLU_CB;
	else
		color = 0x00000000;
	step.x = end.x - start.x;
	step.y = end.y - start.y;
	offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 2);
	offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 2);
	
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