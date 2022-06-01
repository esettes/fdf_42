/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/01 20:28:32 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	fdf_construct(t_fdf *fdf, int fd)//, char *mp)
{
	t_mtrx *mtrx;

	mtrx = (t_mtrx *)malloc(sizeof(t_mtrx));
	obtain_split_fd(fd, mtrx);
	fdf->mtrx = mtrx;
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);    // Creates a new image.
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);   // Adds an image to the render queue.
	fdf->img->instances->x = 50;
	fdf->img->instances->y = 50;
}


// void	fdf_init(t_data img)
// {

// 	while (img->pos->x <= WIDTH +50)
// 	{
// 		img->pos->y += 1;
// 		img->pos->x += 2;
// 		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->edn);	// obtengo dir img
// 		ft_pixel_put(&img, img->pos->x, img->pos->y, RED);	// 
// 		mlx_put_image_to_window(img->mlx, mlx_win, img->img, 0, 0);
		
// 	}
// 	while (img->pos->x >= 0)
// 	{
// 		img->pos->y += 1;
// 		img->pos->x -= 2;
// 		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->edn);
// 		ft_pixel_put(&img, img->pos->x, img->pos->y, RED);
// 		mlx_put_image_to_window(img->mlx, mlx_win, img->img, 0, 0);
		
// 	}
// 	while (img->pos->x <= WIDTH +50)
// 	{
// 		img->pos->y += 1;
// 		img->pos->x += 2;
// 		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->edn);
// 		ft_pixel_put(&img, img->pos->x, img->pos->y, RED);
// 		mlx_put_image_to_window(img->mlx, mlx_win, img->img, 0, 0);
		
// 	}
// 	while (img->pos->x >= 0)
// 	{
// 		img->pos->y += 1;
// 		img->pos->x -= 2;
// 		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->edn);
// 		ft_pixel_put(&img, img->pos->x, img->pos->y, RED);
// 		mlx_put_image_to_window(img->mlx, mlx_win, img->img, 0, 0);
		
// 	}
// 	while (img->pos->x <= WIDTH +50)
// 	{
// 		img->pos->y += 1;
// 		img->pos->x += 2;
// 		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->edn);
// 		ft_pixel_put(&img, img->pos->x, img->pos->y, RED);
// 		mlx_put_image_to_window(img->mlx, mlx_win, img->img, 0, 0);
		
// 	}
// 	while (img->pos->x >= 0)
// 	{
// 		img->pos->y += 1;
// 		img->pos->x -= 2;
// 		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->edn);
// 		ft_pixel_put(&img, img->pos->x, img->pos->y, RED);
// 		mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
		
// 	}
// 	while (img->pos->y >= 0)
// 	{
// 		img->pos->y -= 4;
// 		img->pos->x += 1;
// 		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->edn);
// 		ft_pixel_put(&img, img->pos->x, img->pos->y, 0x00E0FFFF);
// 		mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
// 	}
// 	while (img->pos->y <= -WIDTH +50)
// 	{
// 		img->pos->y -= 4;
// 		img->pos->x -= 2;
// 		img->addr = mlx_get_data_addr(img->img, &img->bpp + 1, &img->l_len, &img->edn);
// 		ft_pixel_put(&img, img->pos->x, img->pos->y, 0x00E0FFFF);
// 		mlx_put_image_to_window(img->mlx, mlx_win, img->img, 0, 0);
// 	}
//}
