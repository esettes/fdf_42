/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/22 03:38:00 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	set_mtrx_size(int x, int y, t_mtrx *mtrx)
{
	t_vec2 segments;
	
	segments.x = x;
	segments.y = y;
	mtrx->px_size.x = mtrx->zoom * y;
	mtrx->px_size.y = mtrx->zoom * x;
	return (segments);
}

void	set_new_zoom(t_fdf *fdf)
{
	t_vec2	segm;

	segm.x = fdf->mtrx.segments.x;
	segm.y = fdf->mtrx.segments.y;
	fdf->mtrx.control.height = 1;
	fdf->mtrx.control.zoom = 1;
	fdf->mtrx.px_size.x = ((segm.y - 1) * fdf->mtrx.zoom);
	fdf->mtrx.px_size.y = ((segm.x - 1) * fdf->mtrx.zoom);
	set_new_limits(fdf);
}

void	set_limits(t_mtrx *mtrx)
{
	mtrx->start.x = (IMG_CENTER_X - (mtrx->px_size.y / 2));
	mtrx->start.y = (IMG_CENTER_Y - (mtrx->px_size.x / 2));
	mtrx->end.x = mtrx->start.x + mtrx->px_size.x;
	mtrx->end.y = mtrx->start.y + mtrx->px_size.y;
}

void	set_new_limits(t_fdf *fdf)
{
	fdf->mtrx.start.x = (IMG_CENTER_X - (fdf->mtrx.px_size.y / 2));
	fdf->mtrx.start.y = (IMG_CENTER_Y - (fdf->mtrx.px_size.x / 2));
	fdf->mtrx.end.x = fdf->mtrx.start.x + fdf->mtrx.px_size.x;
	fdf->mtrx.end.y = fdf->mtrx.start.y + fdf->mtrx.px_size.y;
}


/* limits functons when I try to draw segments at the ssame time */
// void	set_limits(t_mtrx *mtrx)
// {
// 	mtrx->start.x = (IMG_CENTER_X - (mtrx->px_size.x / 2));
// 	mtrx->start.y = (IMG_CENTER_Y - (mtrx->px_size.y / 2));
// 	mtrx->end.x = mtrx->start.x + (mtrx->px_size.x / mtrx->segments.x);
// 	mtrx->end.y = mtrx->start.y + (mtrx->px_size.y / mtrx->segments.y);
// }

// void	set_new_limits(t_fdf *fdf)
// {
// 	fdf->mtrx.start.x = (IMG_CENTER_X - (fdf->mtrx.px_size.x / 2));
// 	fdf->mtrx.start.y = (IMG_CENTER_Y - (fdf->mtrx.px_size.y / 2));
// 	fdf->mtrx.end.x = fdf->mtrx.start.x + (fdf->mtrx.px_size.x / fdf->mtrx.segments.x);
// 	fdf->mtrx.end.y = fdf->mtrx.start.y + (fdf->mtrx.px_size.y / fdf->mtrx.segments.y);
// }

// void	set_limits_isometric(t_fdf *fdf)
// {
	
// }
// t_img_props	get_middle_img()
// {
	// t_vec2	save_aux;
	// t_vec2	img_offset;
	
	// save_aux.x  = ((WIDTH * IMG_AUMENT) / 2) - (WIDTH /2);
	// img_offset.x = ((WIDTH * IMG_AUMENT) / 2) - save_aux.x;
	// save_aux.y  = ((HEIGHT * IMG_AUMENT) / 2) - (HEIGHT /2);
	// img_offset.y = ((HEIGHT * IMG_AUMENT) / 2) - save_aux.y;
// }