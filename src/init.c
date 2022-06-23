/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/15 17:11:33 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_fdf *fdf)
{
	fdf->mtrx.zoom = 1;
	fdf->mtrx.control.height = 1;
	fdf->mtrx.current.x = 0;
	fdf->mtrx.current.y = 0;
	fdf->mtrx.next.x = 0;
	fdf->mtrx.next.y = 0;
	obtain_split_fd(fdf->fd, &fdf->mtrx);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Wire-frame (fdf)", true);
	create_image(fdf);
	draw_image(fdf);
	loop_fdf(fdf);
}
