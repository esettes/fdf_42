/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/30 21:02:11 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char	*argv[])
{ 
	t_fdf	fdf;
	//char	**map;
	int fd;
	int i;

	i = 0;
	if (argv[1])
		printf ("ok");
	if (argc <3)
	{
//		fd = open(argv[1], O_RDONLY);
		fd = open("maps/5-2.txt", O_RDONLY);
		fdf_construct(&fdf);	// hacer obtain_split_fd aquí (?)
		if (fd == -1)
			return (EXIT_FAILURE);
		fdf.mtrx->mtrx = obtain_split_fd(fd);
		//map = obtain_split_fd(fd);
		
		if (!fdf.mlx)
			exit(EXIT_FAILURE);
		//print_matrix(&fdf, &mtrx);
		//draw_simple_line(&fdf);
		close(fdf.fd);
		return (EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}