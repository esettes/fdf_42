/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/26 21:23:24 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_alloc_mtx(t_fdf *fdf, int fd)
{
	char	*mp;
	char	**map;
	int		**mtrx;

	mp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	mp = read_fd(fd, mp);
	if (!mp)
		return (NULL);
	map = ft_split(mp, '\n');
	free(mp);
	mtrx = obtain_int_mtrx(fdf->mtrx ,map);
	return (mtrx);
}

int		**obtain_int_mtrx(t_mtrx *mtrx, char **str)
{
	int		lines;
	char	**cpy;
	int		**m;
	int		count;

	lines = 0;
	cpy = str;
	count = 0;
	while (cpy[lines])
	{
		count += ft_count(cpy[lines], ' ') - 1; // resto 1 por el \n
		lines++;
	}
	mtrx->size->x = count/lines;
	mtrx->size->y = lines;
	m = (malloc(sizeof(int *) * (count + 1)));
	lines = 0;
	while (str[lines])
	{
		m[lines] = ft_atoi(str[lines]);
		lines++;
	}
	return (m);
}

int	ft_count(char const *s, char c)
{
	int	count;
	size_t	bo;
	char	*a;

	count = 0;
	bo = 0;
	a = (char *)s;
	if (!a)
		return (0);
	while (*a)
	{
		if (*a != c && bo == 0)
		{
			count++;
			bo = 1;
		}
		if (*a == c)
			bo = 0;
		a++;
	}
	return (count);
}
