/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:51:18 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/15 15:17:40 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_zoom(double x_delta, double y_delta, void *fdf_void)
{
	t_fdf	*fdf;
	
	fdf = (t_fdf *)fdf_void;
	//free_props(fdf);
//	mlx_delete_image(fdf->mlx, fdf->img);
	if (!fdf_void)
		printf("ok");
	if (y_delta > 0)
	{
		puts("Scroll ++y_delta!");
		if (fdf->mtrx.zoom <= 100)
		{
			fdf->mtrx.zoom += 1;
			modify_mesh(fdf);
		}
	}
	else if (y_delta < 0)
	{
		puts("Scroll --y_delta!");
		if (fdf->mtrx.zoom >= 0)
		{
			fdf->mtrx.zoom -= 1;
			modify_mesh(fdf);
		}
	}
	if (x_delta < 0)
		printf("Sliiiide to the left!");
	else if (x_delta > 0)
		printf("Sliiiide to the right!");
}

// void	free_props(t_fdf *fdf)
// {
// 	if (fdf->mtrx.px_size)
// 		free (fdf->mtrx.px_size);
// 	if (fdf.mtrx.end_draw)
// 		free (fdf->mtrx.end_draw);
// 	if (fdf->mtrx.start_draw)
// 		free (fdf->mtrx.start_draw);
// }
