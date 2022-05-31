/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/31 21:02:18 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char	*argv[])
{ 
	t_fdf	*fdf;
	int fd;
	int i;

	i = 0;
	if (argv[0])
		printf("ok");
	if (argc < 3)
	{
//		fd = open("maps/5-2.txt", O_RDONLY);
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
		{
			exit(EXIT_FAILURE);
			return (EXIT_FAILURE);
		}
		fdf = (t_fdf *)malloc(sizeof(t_fdf));

		fdf_construct(fdf, fd);
		
		if (!fdf->mlx)
			exit(EXIT_FAILURE);
		//print_matrix(&fdf, &mtrx);
		//draw_simple_line(&fdf);
		close(fd);
		return (EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
