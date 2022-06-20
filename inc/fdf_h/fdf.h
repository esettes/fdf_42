/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:06:34 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 13:24:27 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
//# include <unistd.h>
//# include <stdlib.h>
# include <fcntl.h>
# include <memory.h>
# include "gnl.h"
# include "libft.h"
# include "colors.h"
# include "controls.h"
# include "macros.h"
# include "structs.h"
# include "mlx_utils.h"
# include "draw.h"
# include "read_file.h"


/**
 * Sets the pixels of the mesh to calculate where start to print,
 * and the number of segments.
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
 * @param x Mtrx size x.
 * @param y Mtrx size y.
 * 
 * @return t_vec2 with the dummy origin position.
 */
void	set_limits(t_mtrx *mtrx);
void	set_new_limits(t_fdf *fdf);
t_vec2	set_mesh_iso(t_fdf *fdf);


#endif
