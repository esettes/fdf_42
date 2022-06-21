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

void	new_draw_iso(t_fdf *fdf)
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
				
			}
			if (coord.y < fdf->mtrx.px_size.y - 1)
			{
				
			}
			coord.x++;
		}
		coord.y++;
	}
}

// void	f_bresen(t_fdf *fdf)
// {
	
// }