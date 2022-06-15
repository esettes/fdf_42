/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/15 21:15:19 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_box_menu(t_fdf fdf, int color, int max_x, int max_y)
{
	t_vec2	draw;
	t_vec2	aux;
	t_vec2	save_aux;
	t_vec2	start;
	t_vec2	end;

	save_aux.x  = ((WIDTH * IMG_AUMENT) / 2) - (WIDTH /2);
	draw.x = ((WIDTH * IMG_AUMENT) / 2) - (save_aux.x * 0.8);
	save_aux.y  = ((HEIGHT * IMG_AUMENT) / 2) - (HEIGHT /2);
	draw.y = ((HEIGHT * IMG_AUMENT) / 2) - (save_aux.y * 0.8);
	aux.x = draw.x;
	aux.y = draw.y;
	if (1  <= max_x)
	{
		puts("ok");
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
	start.x = aux.x;
	start.y = aux.y;
	end.x = aux.x+ 500;
	end.y = aux.y + 500;
	while (start.y < max_y)
	{
		draw_segment_horiz(start, end, &fdf, color);
		start.y++;
	}
	mlx_put_string(fdf.mlx, "...", aux.x + 10, aux.y + 10);
	
}

void	draw_menu(t_fdf *fdf)
{

	t_vec2	save_aux;

	save_aux.x  = ((WIDTH * IMG_AUMENT) / 2) + (WIDTH * 1.4);
	save_aux.y  = ((HEIGHT * IMG_AUMENT) / 2) + (HEIGHT * 1.4);

	if (fdf) puts("ok");
	print_box_menu(*fdf, MENUDGREY, save_aux.x, save_aux.y);

}
