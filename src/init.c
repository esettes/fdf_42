/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/21 00:31:24 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int		get_matrix_size()
{
	
}*/

void	matrix_construct(t_fdf *fdf)
{
	
	fdf->mtx->mtx = ft_alloc_mtx(fdf->fd);
}

void	fdf_construct(t_fdf *fdf)//, char *mp)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
//	fdf->fd = ft_open(mp);
	fdf->mtx = (t_mtx *)malloc(sizeof(t_mtx));
	fdf->img = mlx_new_image(fdf->mlx, 128, 128);    // Creates a new image.
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);   // Adds an image to the render queue.
	fdf->img->instances->x = 64;
	fdf->img->instances->y = 64;
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
	
// }
