/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/15 20:26:11 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_box_menu(t_fdf fdf, int color, int max_x, int max_y)
{
	t_vec2	draw;
	t_vec2	aux;
	t_vec2	save_aux;

	save_aux.x  = ((WIDTH * IMG_AUMENT) / 2) - (WIDTH /2);
	draw.x = ((WIDTH * IMG_AUMENT) / 2) - save_aux.x;
	save_aux.y  = ((HEIGHT * IMG_AUMENT) / 2) - (HEIGHT /2);
	draw.y = ((HEIGHT * IMG_AUMENT) / 2) - save_aux.y;
	aux.x = draw.x;
	aux.y = draw.y;
	if (draw.x  <= max_x || draw.y <= max_y)
	{
		puts("ok");
		mlx_put_pixel(fdf.img, draw.x, draw.y, menu_rgb(color)); 
		// draw.y = aux.y;
		// while (draw.y <= max_y)
		// {
		// 	if ((int)draw.y % 2 == 0)
		// 		mlx_put_pixel(fdf.img, draw.x, draw.y, menu_rgb(color)); 
		// 	else
		// 		mlx_put_pixel(fdf.img, draw.x, draw.y, menu_rgb(color)); 
		// 	draw.y += 1;
		// }
		// draw.x += 1;
	}
	mlx_put_string(fdf.mlx, "...", aux.x + 10, aux.y + 10);
	printf("\nmiddle img x: %f\n", aux.x);
	printf("\nmiddle img x: %f\n", aux.y);
	
}

void	draw_menu(t_fdf *fdf)
{
	print_box_menu(*fdf, MENUDGREY, (WIDTH * IMG_AUMENT) - (WIDTH / 2) - 20,(HEIGHT * IMG_AUMENT) - (HEIGHT / 2) - 20);
}
