/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/03 22:52:25 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//25x50?
// void	draw_menu_box(t_fdf *fdf)
// {
// 	int	max_y;
// 	int	max_x;

// 	max_y = 
// }

void	draw_menu(t_fdf *fdf)
{
	int			y;
	int			x;
	mlx_t		*mlx;

	y = HEIGHT - 200;
	x = round(WIDTH/1.5); 
	mlx = fdf->mlx;
	mlx_put_string(mlx, "************************", x, y += 24);
	mlx_put_string(mlx, "**  Wire-frame (FDF)  **", x, y += 24);
	mlx_put_string(mlx, "************************", x, y += 24);
}