/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/09 16:22:47 by iostancu         ###   ########.fr       */
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

t_vec2	*set_mtrx_dummy_origin(int x, int y)
{
	t_vec2 *origin;

	origin = (t_vec2 *)malloc(sizeof(t_vec2));
	origin->x = X_ORIGIN_OFF - (x / 2);
	origin->y = Y_ORIGIN_OFF - (y / 2);
	return (origin);
}
