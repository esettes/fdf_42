#include "fdf.h"

void	obtain_mtrx_measure(char **mtrx)
{
	int	i;
	int	j;
	int	row;
	int	col;

	i = 0;
	j = 0;
	row = 0;
	col = 0;
	// while (*(mtrx + j) != '\0')
	// {
		// quitar -fsanitazer o algun debug flag puede hacer que me imprima y me compile 
		// **(mtrx + i), se queda prillado cuando intento printearlo en lldb
		// pero con numeros normales sí funciona
		while (**(mtrx + i) != '\0')
		{
			printf("%c", **(mtrx + i));
			if (ft_isdigit(**(mtrx + i)))	// si es numero, cuenta posicion
			{
				col++;
				i++;
			}
			if (ft_isspace(**(mtrx + i)) || **(mtrx + i) == '-')	// si es otra cosa, pasa
				i++;
			if(**(mtrx + i) == '\n')
			{
				i++;
				row++;
			}
			if (ft_isascii(**(mtrx + i)))
				i++;
		}
		
	// while (mtrx[x][y] != '\0')
	// {
	// 	while (mtrx[x][y] != '\n' && mtrx[x][y] != '\0')
	// 	{
	// 		if (mtrx[x][y] == '-' || mtrx[x][y] == ' ')
	// 		{
	// 			y++;
	// 		}
	// 		printf("%c", mtrx[x][y]);
	// 		cols++;
	// 		y++;
	// 	}
	// 	if (mtrx[x][y] == '\n')
	// 	{
	// 		y++;
	// 		lines++;
	// 	}
	// }
	printf("j %i, rows: %i\n", j, row);
	printf("i %i, cols: %i\n", i, col);

}

void	print_matrix(t_fdf *fdf, t_mtx *mtx)
{
	int	x;
	int	y;
	int	start;

	x = 0;
	y = 0;
	start = fdf->img->instances->y;
	if (fdf)
		printf("fdf is not null! \n");
	// while (mtx->mtx[x] && x < 3)
	// {
	// 	y = 0;
	// 	fdf->img->instances->y = start;
		while (mtx->mtx[x][y] != '\0' && mtx->mtx[x][y] != '\n')
		{
			printf("%c", mtx->mtx[x][y]);
			//fdf->img->instances->x += x;
			// fdf->img->instances->y += y;
			// mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			// 	fdf->img->instances->y, BLUE);
			y++;
		}
		//draw_simple_line(fdf, y);
	// 	//printf("\n");
	// 	x++;
	// }
	
}


void	draw_simple_line(t_fdf *fdf, int max)
{
	int	start;
	start = fdf->img->instances->y;
	while (fdf->img->instances->x <= (max * 5))
	{
		//fdf->img->instances->x += 1;
		fdf->img->instances->y += 1;
		mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			fdf->img->instances->y, BLUE); 
	}
	fdf->img->instances->y = start;
	while (fdf->img->instances->x <= (max * 5))
	{
		//fdf->img->instances->x += 1;
		fdf->img->instances->y += 1;
		mlx_put_pixel(fdf->img, fdf->img->instances->x, 
			fdf->img->instances->y, BLUE); 
	}
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img); // Once the application request an exit, cleanup.
	mlx_terminate(fdf->mlx);
	//free(fdf);
}
