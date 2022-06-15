/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:14:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/15 20:30:35 by iostancu         ###   ########.fr       */
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
	double	aum;
	//double	multip;
	//t_vec2	img_offset;
	t_vec2	save_aux;

	

	// if (fdf->mtrx.segments.x < fdf->mtrx.segments.y)
	// 	multip = fdf->mtrx.segments.y;
	// else
	// 	multip = fdf->mtrx.segments.x;
	aum = 4;
	if (fdf->img)
		mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH * aum, HEIGHT * aum);    // Creates a new image.
	//img_offset.x = ((WIDTH * aum) - WIDTH) / aum;
	//img_offset.y = ((HEIGHT * aum) - HEIGHT) / aum;

	
	// img_offset.x = ((WIDTH * aum) - WIDTH) / aum;
	// img_offset.y = ((HEIGHT * aum) - HEIGHT) / aum;
	//mlx_image_to_window(fdf->mlx, fdf->img, img_offset.x - X_ORIGIN_OFF * aum, img_offset.y - Y_ORIGIN_OFF * aum);
	save_aux.x  = ((WIDTH * IMG_AUMENT) / 2) - (WIDTH /2);
	// img_offset.x = ((WIDTH * IMG_AUMENT) / 2) - save_aux.x;
	save_aux.y  = ((HEIGHT * IMG_AUMENT) / 2) - (HEIGHT /2);
	// img_offset.y = ((HEIGHT * IMG_AUMENT) / 2) - save_aux.y;
	//img_offset.x = ((WIDTH * aum) / 2) - (WIDTH /2) -200;
	//img_offset.y = ((HEIGHT * aum) / 2) - (HEIGHT /2) - 200;
	// printf("\nIn create_image img_offset.x: %f\n", img_offset.x);
	// printf("\nIn create_image img_offset.y: %f\n", img_offset.y);
	printf("\nstart put img x: %f\n", save_aux.x);
	printf("\nstart put img y: %f\n", save_aux.y);
	mlx_image_to_window(fdf->mlx, fdf->img, -save_aux.x, -save_aux.y);   // Adds an image to the render queue.
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
