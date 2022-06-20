/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:12:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 12:39:56 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct s_img_props
{
	t_vec2	middle_img;
}				t_img_props;

/**
 * Save all the values ​​necessary for the mesh construction.
 * 
 * @param[in] mtrx Mesh integer array.
 * @param[in] z Mesh's depth.
 * @param[in] zoom Value that sets the distance between adjoining vertices.
 * @param[in] size Mesh size (x, y).
 */
typedef struct s_mtrx
{
	int		**mtrx;
	int		z;
	int		zoom;
	t_vec2	segments;
	t_vec2	px_size;
	t_vec2	start_draw;
	t_vec2	end_draw;
}				t_mtrx;

/**
 * Main struct of the program, used to store structs initializations
 * required by MLX and program variables. Simplifies the use of the mesh data.
 * 
 * @param mlx Struct required by mlx.
 * @param mtrx Structure for the mesh data.
 * @param img Struct required by mlx.
 */
typedef struct s_fdf
{
	mlx_t		*mlx;
	t_mtrx		mtrx;
	mlx_image_t	*img;		// incluye posic
	int			fd;
}				t_fdf;

#endif