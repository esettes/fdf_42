/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/13 19:44:06 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	set_mtrx_size(int x, int y, t_mtrx *mtrx)
{
	t_vec2 segments;

	if (mtrx->zoom > 0)
	{
		mtrx->px_size.x = ((x - 1) * mtrx->zoom) + x;
		mtrx->px_size.y = ((y - 1) * mtrx->zoom) + y;
	}
	else
	{
		mtrx->px_size.x = x;
		mtrx->px_size.y = y;
	}
	segments.x = x;
	segments.y = y;

	return (segments);
}

void	set_limits(t_mtrx *mtrx)
{
	if (mtrx->zoom > 0)
	{
		mtrx->start_draw.x = X_ORIGIN_OFF - (mtrx->px_size.x / 2);
		mtrx->start_draw.y = Y_ORIGIN_OFF - (mtrx->px_size.y / 2);
	}
	mtrx->end_draw.x = mtrx->start_draw.x + mtrx->px_size.x;
	mtrx->end_draw.y = mtrx->start_draw.y + mtrx->px_size.y;
}
