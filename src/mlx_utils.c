/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:14:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/15 15:34:50 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop_fdf(t_fdf *fdf)
{
	mlx_scroll_hook(fdf->mlx, &set_zoom, fdf);
	
	
	draw_outer_segments(fdf);
	draw_menu(fdf);
	
	mlx_loop(fdf->mlx);
	//mlx_delete_image(fdf->mlx, fdf->img); // Once app request exit, cleanup.
	// mlx_terminate(fdf->mlx);
}

void	create_image(t_fdf *fdf)
{
	double	aument;
	//double	multip;
	t_vec2	img_offset;

	// if (fdf->mtrx.segments.x < fdf->mtrx.segments.y)
	// 	multip = fdf->mtrx.segments.y;
	// else
	// 	multip = fdf->mtrx.segments.x;
	aument = fdf->mtrx.zoom;
	if (fdf->img)
		mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, round(WIDTH * aument), round(HEIGHT * aument));    // Creates a new image.
	img_offset.x = ((WIDTH * aument) - WIDTH) / 2;
	img_offset.y = ((HEIGHT * aument) - HEIGHT) / 2;
	mlx_image_to_window(fdf->mlx, fdf->img, img_offset.x, img_offset.y);   // Adds an image to the render queue.
}

void	draw_image(t_fdf *fdf)
{
	set_new_zoom(fdf);
	draw_outer_segments(fdf);
	draw_menu(fdf);
}

void	modify_mesh(t_fdf *fdf)
{
	create_image(fdf);
	draw_image(fdf);
}


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
