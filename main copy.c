// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   main.c                                             :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
// // /*   Updated: 2022/07/04 16:13:19 by iostancu         ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

// #include "fdf.h"

// typedef struct s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// }				t_data;

// typedef struct s_vars{
// 	void	*mlx;
// 	void	*win;
// 	int		save;
// }t_vars;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void	render_next_frame(void *vars)
// {
// 	//t_data	img;
// 	mlx_image_t *img;
// 	t_vars		*var;
// 	int		i;
// 	int		j;
// 	//int		endian;
// 	var = vars;

// 	i = 0;
// 	img = mlx_new_image(var->mlx, 600, 600);
// 	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
// 	//&img.line_length, &endian);
// 	while (++i < 551)
// 	{
// 		j = 0;
// 		while (++j < 551)
// 		{
// 			if (((j + var->save) / 50) % 2 != 1)
// 				mlx_put_pixel(img, i, j, 0xFF0000FF);
// 			else
// 				mlx_put_pixel(img, i, j, 0xFFFFFFFF);
// 		}
// 	}
// 	mlx_image_to_window(var->mlx, img, 0, 0);
// 	//mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
// 	var->save++;
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.save = 1;
// 	vars.mlx = mlx_init(800,800,"Hello world!", 1);
// 	// vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");
// 	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
// 	// bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);
// 	mlx_loop(vars.mlx);
// }
// //gcc -lmlx -framework OpenGL -framework AppKit  ft_testcol.c -o loops
// // // void	lk(void)
// // // {
// // // 	system("leaks fdf");
// // // }


// // int	main(int argc, char	*argv[])
// // {
// // 	t_fdf	*fdf;
	
// // 	if (argv[0])
// // 		printf("ok");
// // 	// atexit(lk);
// // 	if (argc < 3)
// // 	{
// // 		printf("\norigin offset X: %d\n", X_ORIGIN_OFF);
// // 		printf("origin offset Y: %d\n", Y_ORIGIN_OFF);
// // 		printf("width: %d\n", WIDTH);
// // 		printf("HEIGHT: %d\n\n", HEIGHT);
		
// // 		fdf = (t_fdf *)malloc(sizeof(t_fdf));
// // //		fdf->fd = open("maps/test_maps/pyramide.fdf", O_RDONLY);
// // 		fdf->fd = open(argv[1], O_RDONLY);
// // 		if (fdf->fd <= 0)
// // 		{
// // 			exit(EXIT_FAILURE);
// // 			return (EXIT_FAILURE);
// // 		}
// // 		init_mlx(fdf);
// // 		if (!fdf->mlx)
// // 			exit(EXIT_FAILURE);
// // 		close(fdf->fd);
// // 		return (EXIT_SUCCESS);
// // 	}
// // 	exit(EXIT_FAILURE);
// // 	return (EXIT_FAILURE);
// // }
