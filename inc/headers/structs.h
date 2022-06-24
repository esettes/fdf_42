/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:12:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/24 23:57:14 by iostancu         ###   ########.fr       */
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
 * Sets the params to print two lines, vertical and horizontal, starting from
 * the same point.
 * 
 * @param[in] start Image coordinates where lines start.
 * @param[in] h_end Img coord where horizontal line ends.
 * @param[in] v_end Img coord where vertical line ends.
 */
typedef	struct s_lines
{
	t_vec2	start;
	t_vec2	h_end;
	t_vec2	v_end;
}				t_lines;
/**
 * Save all the values ​​necessary for the mesh construction.
 * 
 * @param[in] mtrx Mesh integer array.
 * @param[in] z Mesh's depth.
 * @param[in] zoom Value that sets the distance between adjoining vertices.
 * @param[in] line Struct which have coords to draw segments.
 * @param[in] segments 'x' represents columns, 'y' represents rows
 * @param[in] px_size Pixel size of a segment.
 * @param[in] start Coord where to start to draw in the img.
 * @param[in] end Coord where to finish to draw in the img.
 * @param[in] current Current position in the array mesh.
 * @param[in] next Next position in the array mesh.
 */
typedef struct s_mtrx
{
	int			**mtrx;
	int			z;
	float		zoom;
	t_lines		line;
	t_vec2		segments;
	t_vec2		px_size;
	t_vec2		start;
	t_vec2		end;
	t_vec2		current;
	t_vec2		next;
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
	t_controls	control;
	mlx_image_t	*img;		// Has position
	int			fd;
}				t_fdf;

#endif