/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:12 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/29 16:56:49 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_view_iso_testing(t_fdf *fdf)
{
	t_vec2	coord;
	//t_vec2	color_coord;
	t_vec2	h_end;
	t_vec2	v_end;

	coord.y = 0;
	
	while (coord.y < fdf->mtrx.vertices.y)
	{
		//printf("\n\e[1;34m**************    in new_view_iso, 	coord.y++ **************\n\e[0m");
		coord.x = 0;
		while (coord.x < fdf->mtrx.vertices.x)
		{
			
			// if (fdf->mtrx.colors[(int)coord.x][(int)coord.y] < 0)
			// 	printf("\n\e[1;34miso_ fdf->mtrx.colors[%i][%i]: \e[1;31m %i\n\e[0m", (int)coord.x, (int)coord.y, fdf->mtrx.colors[(int)coord.x][(int)coord.y]);
			// else
			// 	printf("\n\e[1;34miso_ fdf->mtrx.colors[%i][%i]: %i\n\e[0m", (int)coord.x, (int)coord.y, fdf->mtrx.colors[(int)coord.x][(int)coord.y]);
			if (coord.x < fdf->mtrx.vertices.x - 1)
			{
				//line_horiz(coord, fdf);
				v_end.x = coord.x + 1;
				v_end.y = coord.y;
				f_bresen(fdf, coord, v_end);
			}
			if (coord.y < fdf->mtrx.vertices.y - 1)
			{
				//line_vert(coord, fdf);
				h_end.x = coord.x;
				h_end.y = coord.y + 1;
				f_bresen(fdf, coord, h_end);
			}
			coord.x++;
		}
		coord.y++;
	}
}

void	bresen_put_pixel(t_fdf *fdf, t_vec2 step)
{
	//printf("\nin bresen put_pixel, current.x and current.y: %f, %f\n", fdf->mtrx.current.x, fdf->mtrx.current.y);
	mlx_put_pixel(fdf->img, fdf->mtrx.start.x,
	fdf->mtrx.start.y, rgba(0));
	fdf->mtrx.start.x += step.x;
	fdf->mtrx.start.y += step.y;
}