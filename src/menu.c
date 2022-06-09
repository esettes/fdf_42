/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/09 19:13:09 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//25x50?
void	draw_menu_box(t_fdf *fdf)
{
	t_menu	menu;

	menu.color_1 = 0;
	menu.color_2 = 1;
	menu.max_x_1 = WIDTH - 250;
	menu.max_y_1 = HEIGHT - 170;
	menu.max_x_1 = WIDTH - 150;
	menu.max_y_1 = HEIGHT - 70;
	print_box(*fdf, menu.color_1, menu.max_x_1, menu.max_y_1);
	
}

void	draw_menu(t_fdf *fdf)
{
	int			y;
	int			x;
	mlx_t		*mlx;

	y = round(HEIGHT / 1.25);
	x = round(WIDTH/1.45); 
	mlx = fdf->mlx;
	print_box(*fdf, MENUDGREY, WIDTH - 20, HEIGHT - 20);
	//mlx_put_string(mlx, "************************", x, y += 24);
	mlx_put_string(mlx, "Wire-frame (FDF)", x, y += 20);
	//mlx_put_string(mlx, "************************", x, y += 24);
}
