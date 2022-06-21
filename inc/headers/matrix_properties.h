/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_properties.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:26:48 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/21 22:47:28 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_PROPERTIES_H
# define MATRIX_PROPERTIES_H

# include "structs.h"

/**
 * Saves the mesh size (in pixels) and the number of segments.
 * 
 * @param[in] x Number of vertical segments.
 * @param[in] y Number of horizontal segments.
 * @param[in] mtrx struct matrix.
 * 
 * @return t_vec2 with the number of segments.
 */
t_vec2	set_mtrx_size(int x, int y, t_mtrx *mtrx);
void	init_map_props(t_fdf *fdf);
void	free_props(t_fdf *fdf);
/**
 * Sets the position of the first pixel to start drawing.
 * 
 * @param mtrx The struct mtrx.
 */
void	set_limits(t_mtrx *mtrx);
void	set_new_limits(t_fdf *fdf);
void	set_start_to_print_iso(t_fdf *fdf, t_vec2 *start, t_vec2 *end);

#endif