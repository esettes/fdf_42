/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/11 10:24:06 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_fdf *fdf)
{
	t_vec2	aux;

	aux.x  = (WIDTH * IMG_AUMENT) / 2 - (WIDTH * 0.25);
	aux.y = (HEIGHT * IMG_AUMENT) / 2 - (HEIGHT * 0.25);
	fdf->mtrx.line.start.x = 0;
	fdf->mtrx.line.start.y = 0;
	fdf->mtrx.line.step.x = 0;
	fdf->mtrx.line.step.y = 0;
	fdf->mtrx.line.end.x = 0;
	fdf->mtrx.line.end.y = 0;
	fdf->control.zoom = 1;
	fdf->control.vert = 1;
	fdf->control.horiz = 1;
	fdf->control.perspective = ISOMETRIC;
	obtain_split_fd(fdf->fd, &fdf->mtrx);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Wire-frame (fdf)", true);
	create_image(fdf);
	draw_menu(fdf);
	draw_image(fdf);
	loop_fdf(fdf);
}
