/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:06:34 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/27 22:41:00 by iostancu         ###   ########.fr       */
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
//# include <_int32_t.h>
#include <memory.h>

# define WIDTH			720
# define HEIGHT			420

# define YELLOW	0xFFFF00FF
# define WHITE	0xFFFFFFFF
# define FUCSIA	0xFF00FFFF
# define BLUE	0x2060FFFF
# define PURPLE	0x8040EEFF

typedef struct s_vec2
{
	int	x;
	int	y;
}				t_vec2;

typedef struct s_mtrx
{
	int		**mtrx;
	// int		x;
	// int		y;
	t_vec2	*size;
}				t_mtrx;

typedef struct s_fdf
{
	mlx_t		*mlx;
	t_mtrx		*mtrx;
	mlx_image_t	*img;	// incluye posic
	int32_t		fd;
}				t_fdf;

void	fdf_construct(t_fdf *fdf);//, char *mp);
void	matrix_construct(t_fdf *fdf);

void	draw_simple_line(t_fdf *fdf, int max);
void	print_matrix(t_fdf *fdf, t_mtrx *mtrx);

/*** ***	*** READ MAP ***	*** ***/

int		**ft_alloc_mtx(int fd);
int		**obtain_int_mtrx(char **str);
int		ft_count(char const *s, char c);
int		*str_to_int(const char *str);

#endif
