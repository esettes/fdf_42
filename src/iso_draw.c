/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:12 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/13 19:40:36 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_mesh_iso(t_fdf *fdf)
{
	t_vec2	iso_pos;

	iso_pos.x = get_iso_pos_x(fdf->mtrx);
	iso_pos.y = get_iso_pos_y(fdf->mtrx);
}

double	get_iso_pos_x(t_mtrx mtrx)
{
	t_vec2	size;
	double	pos_x;

	size.x = mtrx.segments.x / 2;
	size.y = mtrx.segments.y / 2;
	pos_x = (size.x) * cos(30) - (size.y * sin(30));
	return (pos_x);
}

double	get_iso_pos_y(t_mtrx mtrx)
{
	t_vec2	size;
	double	pos_y;

	size.x = mtrx.segments.x / 2;
	size.y = mtrx.segments.y / 2;
	pos_y = (size.x) * sin(30) + (size.y * cos(30));
	return (pos_y);
}