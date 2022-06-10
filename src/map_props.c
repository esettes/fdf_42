/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/10 19:08:07 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	*set_mtrx_size(int x, int y)
{
	t_vec2 *size;

	size = (t_vec2 *)malloc(sizeof(t_vec2));
	size->x = x;
	size->y = y;
	return (size);
}

void	set_limits(int x, int y, t_mtrx *mtrx)
{
	mtrx->start_draw = (t_vec2 *)malloc(sizeof(t_vec2));
	mtrx->end_draw = (t_vec2 *)malloc(sizeof(t_vec2));
	mtrx->start_draw->x = X_ORIGIN_OFF - (x / 2);
	mtrx->start_draw->y = Y_ORIGIN_OFF - (y / 2);
	mtrx->end_draw->x = mtrx->start_draw->x + mtrx->size->x;
	mtrx->end_draw->y = mtrx->start_draw->y + mtrx->size->y;
}
