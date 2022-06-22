/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:12:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/22 04:05:31 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "MLX42.h"
# include <math.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct s_depth
{
	int	z;
	int	z1;
}				t_depth;

typedef struct s_iter
{
	int	i;
	int	j;
}				t_iter;

typedef	struct s_controls
{
	float	height;
	float	zoom;
}				t_controls;
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
	int			**mtrx;
	int			z;
	float		zoom;
	t_controls	control;
	t_vec2		segments;
	t_vec2		px_size;
	t_vec2		start;
	t_vec2		end;
	int			**depth;
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