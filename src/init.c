/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/08 19:06:40 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_fdf *fdf)
{
	t_vec2	aux;
	t_vec2	save_aux;

	save_aux.x  = (WIDTH * IMG_AUMENT) / 2 - (WIDTH * 0.25);
	save_aux.y = (HEIGHT * IMG_AUMENT) / 2 - (HEIGHT * 0.25);
	aux.x = save_aux.x;
	aux.y = save_aux.y;
	fdf->control.zoom = 1;
	fdf->control.vert = 1;
	fdf->control.horiz = 1;
	fdf->control.perspective = ISOMETRIC;
	obtain_split_fd(fdf->fd, &fdf->mtrx);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Wire-frame (fdf)", true);
	create_image(fdf);
	mlx_put_string(fdf->mlx, "CONTROLS", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, " -Scroll for zoom", aux.x + 10, aux.y += 22);
	draw_image(fdf);
	loop_fdf(fdf);
}
