/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/13 17:49:59 by iostancu         ###   ########.fr       */
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
		printf("\norigin offset X: %d\n", X_ORIGIN_OFF);
		printf("origin offset Y: %d\n", Y_ORIGIN_OFF);
		printf("width: %d\n", WIDTH);
		printf("HEIGHT: %d\n\n", HEIGHT);
		fd = open("maps/100-6.fdf", O_RDONLY);
//		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
		{
			exit(EXIT_FAILURE);
			return (EXIT_FAILURE);
		}
		fdf = (t_fdf *)malloc(sizeof(t_fdf));

		fdf_construct(fdf, fd);
		start_mlx(fdf);
		if (!fdf->mlx)
			exit(EXIT_FAILURE);
		
		close(fd);
		return (EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
} 

