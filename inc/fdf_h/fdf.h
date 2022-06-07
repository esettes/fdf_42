/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:06:34 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/07 20:59:29 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line_bonus.h"
# include "libft.h"
# include "colors.h"
//# include <_int32_t.h>
#include <memory.h>

# define WIDTH		1600
# define HEIGHT		900
# define OFFSET		50


typedef struct s_menu
{
	int		color_1;
	int		color_2;
	int		max_x_1;
	int		max_y_1;
	int		max_x_2;
	int		max_y_2;
}				t_menu;


typedef struct s_vec2
{
	int	x;
	int	y;
}				t_vec2;
/**
 * Save all the values ​​necessary for the mesh construction.
 * 
 * @param mtrx Mesh integer array.
 * @param z Mesh's depth.
 * @param zoom Value that sets the distance between adjoining vertices.
 * @param size Mesh size (x, y).
 */
typedef struct s_mtrx
{
	int		**mtrx;
	int		z;
	int		zoom;
	t_vec2	*size;
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
	t_mtrx		*mtrx;
	mlx_image_t	*img;	// incluye posic
}				t_fdf;

/* Initializes the main parameters of the application */
void	fdf_construct(t_fdf *fdf, int fd);
/* Calls all functions that need mlx_loop to run */
void	start_mlx(t_fdf *fdf);

void	draw_simple_line(t_fdf *fdf, int max);

/*			Read map			*/

char	**obtain_lines(int fd);
/**
 * Receives the previously opened fd, which is to be converted to a double
 * pointer array and stored in *m.
 * 
 * @param[in] fd File already open.
 * @param[in] m Struct where the conversion will be saved.
 */
void	obtain_split_fd(int fd, t_mtrx *m);
/**
 * Returns the number words of *s separated by 'c'
 */
int		ft_count(char const *s, char c);
/**
 * Returns the conversion of *str to an integer string
 */
int		*str_to_int(char *str);

/*			Map properties			*/

/**
 * Saves the size of the wire-frame of the main program
 */
t_vec2	*set_mtrx_size(int x, int y);
/**
 * Gets the origin of the map(0, 0) and makes a copy of it.
 *
 * @return Copy of original mtrx with new coords.
 */
void	get_mtrx_origin(t_mtrx mtrx);

/***		Print map		***/

void	print_mesh(t_fdf *fdf);
void	draw_to_nxt_pt(t_fdf *fdf);
void	set_sx(int x0, int x1, int *sx);
void	set_sy(int y0, int y1, int *sy);
void	set_pixel(t_fdf *fdf);

/*			Draw tools			*/

/**
 * Returns an hex color from red (value < 0.1) , through green,
 *  to blue (value > 0.8) 
 */
int		rgba(double value);

/*			Print menu			*/

void	draw_menu(t_fdf *fdf);
void	print_box(t_fdf fdf, int color, int max_x, int max_y);
int 	menu_rgb(int value);
void	draw_menu_box(t_fdf *fdf);

#endif
