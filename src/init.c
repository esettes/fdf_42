/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/07 21:47:22 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_fdf *fdf)
{
	//t_controls	*controls;

	//controls = (t_controls *)malloc(sizeof(t_controls));
	//fdf->control = controls;
	fdf->control.zoom = 1;
	fdf->control.vert = 1;
	fdf->control.horiz = 1;
	obtain_split_fd(fdf->fd, &fdf->mtrx);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Wire-frame (fdf)", true);
	create_image(fdf);
	draw_image(fdf);
	loop_fdf(fdf);
}
