/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:12 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/05 19:54:13 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_view_iso_testing(t_fdf *fdf)
{
	t_vec2	coord;
	//t_vec2	color_coord;
	t_vec2	before;
	t_vec2	h_end;
	t_vec2	v_end;

	coord.y = 1;
	
	while (coord.y < fdf->mtrx.vertices.y)
	{
		//printf("\n\e[1;34m**************    in new_view_iso, 	coord.y++ **************\n\e[0m");
		coord.x = 1;
		while (coord.x < fdf->mtrx.vertices.x)
		{
			before.x = coord.x;
			before.y = coord.y;
			if (coord.x < fdf->mtrx.vertices.x - 1)
			{
				//line_horiz(coord, fdf);
				v_end.x = coord.x + 1;
				v_end.y = coord.y;
				f_bresen(fdf, coord, v_end, 0);
			}
			if (coord.y < fdf->mtrx.vertices.y - 1)
			{
				//line_vert(coord, fdf);
				h_end.x = coord.x;
				h_end.y = coord.y + 1;
				f_bresen(fdf, coord, h_end, 1);
			}
			coord.x++;
		}
		coord.y++;
	}
}
