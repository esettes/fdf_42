/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 03:25:12 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	set_mtrx_size(int x, int y)
{
	t_vec2 vertices;
	
	vertices.x = x;
	vertices.y = y;
	return (vertices);
}

void	set_pixel_size(t_fdf *fdf)
{
	fdf->mtrx.px_size.x = fdf->control.zoom * fdf->mtrx.vertices.x;
	fdf->mtrx.px_size.y = fdf->control.zoom * fdf->mtrx.vertices.y;
}

void	set_new_zoom(t_fdf *fdf)
{
	fdf->mtrx.px_size.x = fdf->control.zoom * (fdf->mtrx.vertices.x - 1);
	fdf->mtrx.px_size.y = fdf->control.zoom * (fdf->mtrx.vertices.y - 1);
	set_limits(&fdf->mtrx);
}

// void	set_new_zoom(t_fdf *fdf)
// {
// 	t_vec2	segm;

// 	segm.x = fdf->mtrx.vertices.x;
// 	segm.y = fdf->mtrx.vertices.y;
// 	fdf->mtrx.px_size.x = ((segm.y - 1) * fdf->control.zoom);
// 	fdf->mtrx.px_size.y = ((segm.x - 1) * fdf->control.zoom);
// 	set_new_limits(fdf);
// }

void	set_limits(t_mtrx *mtrx)
{
	mtrx->start.x = (IMG_CENTER_X - (mtrx->px_size.x / 2));
	mtrx->start.y = (IMG_CENTER_Y - (mtrx->px_size.y / 2));
	mtrx->end.x = mtrx->start.x + mtrx->px_size.x;
	mtrx->end.y = mtrx->start.y + mtrx->px_size.y;
}

void	set_new_limits(t_fdf *fdf)
{
	fdf->mtrx.start.x = (IMG_CENTER_X - (fdf->mtrx.px_size.x / 2));
	fdf->mtrx.start.y = (IMG_CENTER_Y - (fdf->mtrx.px_size.y / 2));
	fdf->mtrx.end.x = fdf->mtrx.start.x + fdf->mtrx.px_size.x;
	fdf->mtrx.end.y = fdf->mtrx.start.y + fdf->mtrx.px_size.y;
}


/* limits functons when I try to draw vertices at the ssame time */
// void	set_limits(t_mtrx *mtrx)
// {
// 	mtrx->start.x = (IMG_CENTER_X - (mtrx->px_size.x / 2));
// 	mtrx->start.y = (IMG_CENTER_Y - (mtrx->px_size.y / 2));
// 	mtrx->end.x = mtrx->start.x + (mtrx->px_size.x / mtrx->vertices.x);
// 	mtrx->end.y = mtrx->start.y + (mtrx->px_size.y / mtrx->vertices.y);
// }

// void	set_new_limits(t_fdf *fdf)
// {
// 	fdf->mtrx.start.x = (IMG_CENTER_X - (fdf->mtrx.px_size.x / 2));
// 	fdf->mtrx.start.y = (IMG_CENTER_Y - (fdf->mtrx.px_size.y / 2));
// 	fdf->mtrx.end.x = fdf->mtrx.start.x + (fdf->mtrx.px_size.x / fdf->mtrx.vertices.x);
// 	fdf->mtrx.end.y = fdf->mtrx.start.y + (fdf->mtrx.px_size.y / fdf->mtrx.vertices.y);
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