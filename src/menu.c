/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/11 09:44:44 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_box_menu(t_fdf *fdf, int color, int max_x, int max_y)
{
	t_vec2	draw;
	t_vec2	aux;
	t_vec2	save_aux;
	float	temp;

	save_aux.x  = (WIDTH * IMG_AUMENT) / 2 - (WIDTH * 0.25);
	save_aux.y = (HEIGHT * IMG_AUMENT) / 2 - (HEIGHT * 0.25);
	draw.x = (WIDTH * IMG_AUMENT) / 2 + (WIDTH / 2) - 300;
	draw.y = (HEIGHT * IMG_AUMENT) / 2 + (HEIGHT / 2) - 100;
	aux.x = save_aux.x;
	aux.y = save_aux.y;
	temp = draw.y;
	printf("start draw x, y: %f, %f\n", save_aux.x, save_aux.y);
	while (draw.x  < max_x)
	{
		draw.y = temp;
		
		while (draw.y <= max_y)
		{
			mlx_put_pixel(fdf->img, draw.x, draw.y, menu_rgb(color)); 
			draw.y += 1;
		}
		draw.x += 1;
	}
	
	mlx_put_string(fdf->mlx, "middle", (WIDTH * IMG_AUMENT) / 2, (HEIGHT * IMG_AUMENT) / 2);
	printf("middle draw x, y: %f, %f\n", (WIDTH * IMG_AUMENT) / 2, (HEIGHT * IMG_AUMENT) / 2);
	mlx_put_string(fdf->mlx, "CONTROLS", aux.x + 10, aux.y += 22);
	printf("conrtols draw x, y: %f, %f\n", aux.x + 10, aux.y + 10);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, " -Scroll for zoom", aux.x + 10, aux.y += 22);
	
}

// void	draw_menu(t_fdf *fdf)
// {
// 	t_vec2	save_aux;

// 	save_aux.x  = (WIDTH * IMG_AUMENT) / 2 - (WIDTH / 5);
// 	save_aux.y  = (HEIGHT * IMG_AUMENT) / 2 - (HEIGHT / 5);
// 	printf("end draw x, y: %f, %f\n", save_aux.x, save_aux.y);
// 	print_box_menu(fdf, 0, save_aux.x, save_aux.y);
// }

void	draw_menu(t_fdf *fdf)
{
	t_vec2	aux;

	aux.x  = (WIDTH * IMG_AUMENT) / 2 - (WIDTH * 0.25);
	aux.y = (HEIGHT * IMG_AUMENT) / 2 - (HEIGHT * 0.25);
	mlx_put_string(fdf->mlx, "CONTROLS", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "Scroll for zoom", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[W] or Up arrow to move up", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[S] or Down arrow to move down", aux.x + 10, aux.y += 22);
}