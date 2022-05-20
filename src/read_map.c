/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/21 01:07:52 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_mtx(t_fdf *fdf, char **str)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (**(str + y))
	{
		x = 0;
		while (ft_strncmp(*(str + x), "\n", 11) != 0)
		{
			fdf->img->instances->x += x;
			fdf->img->instances->y += y;
			mlx_put_pixel(fdf->img, fdf->img->instances->x, 
				fdf->img->instances->y, BLUE);
			x++;

		}
		y++;
	}
}

char	**ft_alloc_mtx(int fd)
{
	char	*mp;
	char	**map;

	mp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	mp = read_fd(fd, mp);
	map = ft_split(mp, '\n');
	free(mp);
	return (map);
}
