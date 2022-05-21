/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/21 02:07:50 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include "MLX42.h"

// Arreglar error " libdyld.dylib`stack_not_16_byte_aligned_error" parece estar entre ft_alloc_mtx y ft_split

/**
 * Process 21668 stopped
 * thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=EXC_I386_GPFLT)
 *   frame #0: 0x00007fff6a1283a6 libdyld.dylib`stack_not_16_byte_aligned_error

 * stack_not_16_byte_aligned_error @ /usr/lib/system/libdyld.dylib:
 *->  0x7fff6a1283a6 (0x23a6): 66 0f 7f 04 24  movdqa   xmmword ptr [rsp], xmm0
 *  0x7fff6a1283ab (0x23ab): cc              int3     
 *_dyld_fast_stub_entry(void*, long) @ /usr/lib/system/libdyld.dylib:
 *   0x7fff6a1283ac (0x23ac): 55              push     rbp
 *   0x7fff6a1283ad (0x23ad): 48 89 e5        mov      rbp, rsp
 */

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