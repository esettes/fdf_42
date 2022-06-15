/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/15 17:22:15 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	set_mtrx_size(int x, int y, t_mtrx *mtrx)
{
	t_vec2 segments;
	
	mtrx->px_size.x = x;
	mtrx->px_size.y = y;
	segments.x = x;
	segments.y = y;
	return (segments);
}

void	set_new_zoom(t_fdf *fdf)
{
	t_vec2	segm;

	segm.x = fdf->mtrx.segments.x;
	segm.y = fdf->mtrx.segments.y;
	fdf->mtrx.px_size.x = (int)((segm.x - 1) * fdf->mtrx.zoom);
	fdf->mtrx.px_size.y = (int)((segm.y - 1) * fdf->mtrx.zoom);
	set_new_limits(fdf);
}

void	set_limits(t_mtrx *mtrx)
{
	mtrx->start_draw.x = (WIDTH / 2) - (mtrx->px_size.x / 2);
	mtrx->start_draw.y = (HEIGHT / 2) - (mtrx->px_size.y / 2);
	mtrx->end_draw.x = mtrx->start_draw.x + mtrx->px_size.x;
	mtrx->end_draw.y = mtrx->start_draw.y + mtrx->px_size.y;
}

void	set_new_limits(t_fdf *fdf)
{
	fdf->mtrx.start_draw.x = (fdf->img->width / 2) - (fdf->mtrx.px_size.x / 2);
	fdf->mtrx.start_draw.y = (fdf->img->height / 2) - (fdf->mtrx.px_size.y / 2);
	fdf->mtrx.end_draw.x = fdf->mtrx.start_draw.x + fdf->mtrx.px_size.x;
	fdf->mtrx.end_draw.y = fdf->mtrx.start_draw.y + fdf->mtrx.px_size.y;
}
