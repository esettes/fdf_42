/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:14:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/15 00:25:24 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	*new_win(void *mlx, int h, int w, char *str)
// {
	//void	*mlx_win;
// 	mlx_new_window(mlx, h, w, str);
	//mlx_loop(mlx);
// }
// knowing image address, eficient implementation mlx_pixel_put


/*void	ft_bresenham()
{
	///	Buscar otra implementacion de bresenham
}

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
