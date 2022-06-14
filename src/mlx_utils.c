/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:14:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/14 21:13:40 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_mlx(t_fdf *fdf)
{
	double	aument;
	t_mtrx	mtrx;

	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Wire-frame (fdf)", true);
	obtain_split_fd(fdf->fd, &mtrx);
	fdf->mtrx = mtrx;
	aument = 1.5;

	
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);

	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	mlx_scroll_hook(fdf->mlx, &set_zoom, fdf);
	
	draw_outer_segments(fdf);
	draw_menu(fdf);
	
	
	mlx_loop(fdf->mlx);
	//mlx_delete_image(fdf->mlx, fdf->img); // Once app request exit, cleanup.
	// mlx_terminate(fdf->mlx);
}

void	loop_fdf()
{
	
}

// void	resize_mesh(t_fdf *fdf)
// {
	
// }

/*
void	transform_iso(t_mtrx *mtrx)
{
	double	x1;
	double	y1;

	// obtener centro del mapa

	// colocar el centro del mapa en 0, 0 y ajustar coords

	// aplicar giro

	// aplicar nnuevas coordenadas a la imagen existente
}
 */


/*
void _bresenham(int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	p;

	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	p = p * dy - dx;
	while (x < x2)
	{
		if(p >= 0)
		{
			ft_pixel_put(x, y, 7);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			ft_pixel_put(x, y, 7);
			p = p + 2 * dy;
		}
		x += 1;
	}
}*/
