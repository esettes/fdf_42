/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:06:34 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/01 20:18:03 by iostancu         ###   ########.fr       */
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
# define OFFSET			50

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
	int		z;
	t_vec2	*size;
}				t_mtrx;

typedef struct s_fdf
{
	mlx_t		*mlx;
	t_mtrx		*mtrx;
	mlx_image_t	*img;	// incluye posic
}				t_fdf;

void	fdf_construct(t_fdf *fdf, int fd);

void	draw_simple_line(t_fdf *fdf, int max);

/***		Read map		***/

char	**obtain_lines(int fd);
// alloc mem for **map and *size map and set values
void	obtain_split_fd(int fd, t_mtrx *m);
int		**obtain_int_mtrx(char **str);
int		ft_count(char const *s, char c);
int		*str_to_int(char *str);

/***		Map props		***/
t_vec2	*set_mtrx_size(int x, int y);

/***		Print map		***/
void	print_mesh(t_fdf *fdf);

#endif
