/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/14 20:50:46 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	init_map_props(t_fdf *fdf)
// {
	
	
	
// }

t_vec2	set_mtrx_size(int x, int y, t_mtrx *mtrx)
{
	t_vec2 segments;
	*mtrx->zoom = 1;
	//mtrx->zoom = 5;

	// if (mtrx->zoom > 0)
	// {
	// 	mtrx->px_size.x = (int)((x - 1) * mtrx->zoom);// + x;
	// 	mtrx->px_size.y = (int)((y - 1) * mtrx->zoom);// + y;
	// }
	// else
	// {
	mtrx->px_size = (t_vec2 *)malloc(sizeof(t_vec2));
	mtrx->px_size->x = x;
	mtrx->px_size->y = y;
	//}
	segments.x = x;
	segments.y = y;

	return (segments);
}



void	set_new_zoom(t_fdf *fdf)
{
	t_vec2	segm;

	segm.x = fdf->mtrx.segments.x;
	segm.y = fdf->mtrx.segments.y;
	fdf->mtrx.px_size->x = (int)((segm.x - 1) * *fdf->mtrx.zoom);
	fdf->mtrx.px_size->y = (int)((segm.y - 1) * *fdf->mtrx.zoom);
	set_limits(&fdf->mtrx);
}

void	set_limits(t_mtrx *mtrx)
{
	mtrx->start_draw = (t_vec2 *)malloc(sizeof(t_vec2));
	mtrx->end_draw = (t_vec2 *)malloc(sizeof(t_vec2));
	mtrx->start_draw->x = X_ORIGIN_OFF - (mtrx->px_size->x / 2);
	mtrx->start_draw->y = Y_ORIGIN_OFF - (mtrx->px_size->y / 2);
	mtrx->end_draw->x = mtrx->start_draw->x + mtrx->px_size->x;
	mtrx->end_draw->y = mtrx->start_draw->y + mtrx->px_size->y;
}
