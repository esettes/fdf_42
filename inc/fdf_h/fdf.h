/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:06:34 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/20 23:01:36 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# include "MLX42.h"
# include "get_next_line_bonus.h"
# include "libft.h"
//#include <memory.h>

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

typedef struct s_mtx
{
	char	**mtx;
	t_vec2	*size;
}				t_mtx;

typedef struct s_fdf
{
	mlx_t		*mlx;
	t_mtx		*mtx;
	mlx_image_t	*img;	// incluye posic
	int			fd;
}				t_fdf;

void	fdf_construct(t_fdf *fdf);//, char *mp);
void	draw_simple_line(t_fdf *fdf);
char	**ft_alloc_mtx(int fd);
void	print_mtx(t_fdf *fdf);

#endif
