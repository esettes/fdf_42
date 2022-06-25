/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:12 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 03:07:09 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_view_iso_testing(t_fdf *fdf)
{
	t_vec2	coord;
	t_vec2	h_end;
	t_vec2	v_end;
	//int		**mesh;

	coord.y = 0;
	//mesh = &fdf->mtrx;
	while (coord.y < fdf->mtrx.vertices.y)
	{
		coord.x = 0;
		while (coord.x < fdf->mtrx.vertices.x)
		{
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







// t_depth	set_depth(t_fdf *fdf)//, t_vec2 coord)
// {
// 	t_depth	dep;
// 	int		**mesh;

// 	mesh = fdf->mtrx.mtrx;
// 	/* Aplicar control a la coordenada de mesh, luego llevarlo a la coordenada de la imagen? */
// 	/*dep.z = mesh[(int)fdf->mtrx.start.y][(int)fdf->mtrx.start.x] 
// 		* fdf->mtrx.control.height;
// 	dep.z1 = mesh[(int)fdf->mtrx.end.y][(int)fdf->mtrx.end.x] 
// 		* fdf->mtrx.control.height;*/
// 	dep.z = mesh[(int)fdf->mtrx.current.x][(int)fdf->mtrx.current.y] 
// 		* fdf->mtrx.control.height;
// 	dep.z1 = mesh[(int)fdf->mtrx.next.x][(int)fdf->mtrx.next.y] 
// 		* fdf->mtrx.control.height;
// 	printf("\nin set_depth, dep.z and dep.z1: %i, %i\n", dep.z, dep.z1);
// 	return (dep);
// }

void	bresen_put_pixel(t_fdf *fdf, t_vec2 step)
{
	printf("\nin bresen put_pixel, current.x and current.y: %f, %f\n", fdf->mtrx.current.x, fdf->mtrx.current.y);
	mlx_put_pixel(fdf->img, fdf->mtrx.start.x,
		fdf->mtrx.start.y, rgba(0));
	fdf->mtrx.start.x += step.x;
	fdf->mtrx.start.y += step.y;
}