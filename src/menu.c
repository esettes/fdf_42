/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 12:04:46 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_box_menu(t_fdf fdf, int color, int max_x, int max_y)
{
	t_vec2	draw;
	t_vec2	aux;
	t_vec2	save_aux;

	save_aux.x  = ((WIDTH * IMG_AUMENT) / 2) + (WIDTH * 0.3);
	draw.x = ((WIDTH * IMG_AUMENT) / 2) - (save_aux.x * 0.8);
	save_aux.y  = ((HEIGHT * IMG_AUMENT) / 2) + (HEIGHT * 0.1);
	draw.y = ((HEIGHT * IMG_AUMENT) / 2) - (save_aux.y * 0.8);
	aux.x = draw.x;
	aux.y = draw.y;

	while (save_aux.x  <= max_x)
	{
		save_aux.y = aux.y;
		
		while (save_aux.y <= max_y)
		{
			mlx_put_pixel(fdf.img, save_aux.x, save_aux.y, menu_rgb(color)); 
			save_aux.y += 1;
		}
		save_aux.x += 1;
	}
	printf("finish print box Y: %f\n", save_aux.y);
	// start.x = aux.x;
	// start.y = aux.y;
	// end.x = aux.x+ 500;
	// end.y = aux.y + 500;
	// while (start.y < max_y)
	// {
	// 	draw_segment_horiz(start, end, &fdf, color);
	// 	start.y++;
	// }
	mlx_put_string(fdf.mlx, "CONTROLS", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf.mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf.mlx, " -Scroll for zoom", aux.x + 10, aux.y += 22);
	
}

void	draw_menu(t_fdf *fdf)
{
	t_vec2	save_aux;

	save_aux.x  = ((WIDTH * IMG_AUMENT) / 2) + (WIDTH * 0.8);
	save_aux.y  = ((HEIGHT * IMG_AUMENT) / 2) + (HEIGHT * 0.8);

	
	print_box_menu(*fdf, 0, save_aux.x, save_aux.y);
}
