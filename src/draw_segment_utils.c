/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:10:47 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/13 15:28:02 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_s(t_vec2 start, t_vec2 end, t_vec2 *s)
{
	if (start.x < end.x)
		s->x = 1;
	else if (start.x >= end.x)
		s->x = -1;
	if (start.y < end.y)
		s->y = 1;
	else if (start.y >= end.y)
		s->y = -1;
}

// void	set_sx(int x0, int x1, int *sx)
// {
// 	if (x0 < x1)
// 		*sx = 1;
// 	else
// 		*sx = -1;
// }

// void	set_sy(int y0, int y1, int *sy)
// {
// 	if (y0 < y1)
// 		sy = 1;
// 	else
// 		sy = -1;
// }

void	set_d(t_vec2 start, t_vec2 end, t_vec2 *d)
{
	d->x = fabs(end.x - start.x);
	d->y = -fabs(end.y - start.y);
}
