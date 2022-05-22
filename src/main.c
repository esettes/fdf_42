/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/22 22:37:26 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char	*argv[])
{ 
	t_fdf	fdf;
	t_mtx	mtrx;
	int fd;

	if (argc <3)
	{
		fd = open(argv[1], O_RDONLY);
//		fd = open("maps/10-2.txt", O_RDONLY);
		fdf_construct(&fdf);

		mtrx.mtx = ft_alloc_mtx(fd);
		
		
		if (!fdf.mlx)
			exit(EXIT_FAILURE);
		print_matrix(&fdf, &mtrx);
		//draw_simple_line(&fdf);
		close(fdf.fd);
		return (EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}