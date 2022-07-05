// // #include <mlx.h>
// # include "./inc/MLX42/include/MLX42/MLX42.h"
// #include <unistd.h>

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

// int	render_next_frame(t_vars *vars)
// {
// 	t_data	img;
// 	int		i;
// 	int		j;
// 	int		endian;

// 	i = 0;
// 	img.img = mlx_new_image(vars->mlx, 600, 600);
// 	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
// 	&img.line_length, &endian);
// 	while (++i < 551)
// 	{
// 		j = 0;
// 		while (++j < 551)
// 		{
// 			if (((j + vars->save) / 50) % 2 != 1)
// 				my_mlx_pixel_put(&img, i, j, 0x00FF0000);
// 			else
// 				my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
// 		}
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
// 	vars->save++;
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.save = 1;
// 	vars.mlx = mlx_init(800,800,"Hello world!", 1);
// 	// vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");
// 	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
// 	mlx_loop(vars.mlx);
// }
// //gcc -lmlx -framework OpenGL -framework AppKit  ft_testcol.c -o loops