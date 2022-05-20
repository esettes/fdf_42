/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/21 01:27:54 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include "MLX42.h"

int	main(int argc, char	*argv[])
{ 
	t_fdf	*fdf;
	char	**str;
	int fd;

	if (argc <3)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		fd = open(argv[1], O_RDONLY);
		fdf_construct(fdf);
		//fdf->mtx->mtx = ft_alloc_mtx(fdf->fd);
		str = ft_alloc_mtx(fd);
		print_mtx(fdf, str);
		// while (*(fdf->mtx->mtx))
		// {
		// 	while (&fdf->mtx->mtx != "\n"){
		// 		printf("%c\n", &fdf->mtx->mtx);
		// 	}
		// 	fdf->mtx->mtx++;
		// }
		
		
		if (!fdf->mlx)
			exit(EXIT_FAILURE);
		draw_simple_line(fdf);
		close(fdf->fd);
		//free(fdf);
		return (EXIT_SUCCESS);
	}
	system("leaks a.out");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}