/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:06:34 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/09 16:53:12 by iostancu         ###   ########.fr       */
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
#include <memory.h>

# define WIDTH		1600
# define HEIGHT		900
# define OFFSET		50
# define X_ORIGIN_OFF	( WIDTH / 2 )
# define Y_ORIGIN_OFF	( HEIGHT / 2 )
// # define ORIGIN_OFF	( sqrt(pow(HEIGHT, 2) + pow(WIDTH, 2)) / 2 )


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
	double	x;
	double	y;
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
	t_vec2	*dummy_orig;
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
 * Saves the size of the wire-frame of the main program.
 * 
 * @return t_vec2 with the mtrx size.
 */
t_vec2	*set_mtrx_size(int x, int y);
/**
 * Sets the dummy origin (0, 0) of the mesh, depending of the window size.
 * 
 * @param x Mtrx size x.
 * @param y Mtrx size y.
 * 
 * @return t_vec2 with the dummy origin position.
 */
t_vec2	*set_mtrx_dummy_origin(int x, int y);

/***		Print map		***/

void	print_mesh(t_fdf *fdf);
/**
 * Prints map without depth at the window dummy origin. It moves
 * the first pixel to print at the middle of the window, and then 
 * substracts sizemap x and y to it.
 */
void	print_mesh_at_origin(t_fdf *fdf);
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
