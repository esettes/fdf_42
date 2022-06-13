/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/13 15:27:37 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_box_menu(t_fdf fdf, int color, int max_x, int max_y)
{
	t_vec2	draw;
	t_vec2	aux;

	draw.x = round(WIDTH / 1.50);
	draw.y = round(HEIGHT / 1.2);
	aux.x = draw.x;
	aux.y = draw.y;
	while (draw.x  <= max_x)
	{
		draw.y = aux.y;
		while (draw.y <= max_y)
		{
			if ((int)draw.y % 2 == 0)
				mlx_put_pixel(fdf.img, draw.x, draw.y, menu_rgb(color)); 
			else
				mlx_put_pixel(fdf.img, draw.x, draw.y, menu_rgb(color)); 
			draw.y += 1;
		}
		draw.x += 1;
	}
	mlx_put_string(fdf.mlx, "Menu", aux.x + 10, aux.y + 10);
}

void	draw_menu(t_fdf *fdf)
{
	print_box_menu(*fdf, MENUDGREY, WIDTH - 20, HEIGHT - 20);
}
 