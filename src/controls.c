/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:51:18 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/14 19:54:14 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_zoom(double x_delta, double y_delta, void *fdf_void)
{
	// t_fdf	*fdf;
	
	// fdf = (t_fdf *)fdf_void;
//	mlx_delete_image(fdf->mlx, fdf->img);
	if (!fdf_void)
		printf("ok");
	if (y_delta > 0)
	{
		puts("Scroll ++y_delta!");
		// if (fdf->mtrx.zoom <= 20)
		// 	fdf->mtrx.zoom += 2;
	}
	else if (y_delta < 0)
	{
		puts("Scroll --y_delta!");
		// if (fdf->mtrx.zoom >= 0)
		// 	fdf->mtrx.zoom -= 2;
	}
	if (x_delta < 0)
		printf("Sliiiide to the left!");
	else if (x_delta > 0)
		printf("Sliiiide to the right!");
}
