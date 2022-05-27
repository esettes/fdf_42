/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/27 22:51:07 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_alloc_mtx(int fd)
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
	mtrx = obtain_int_mtrx(map);
	return (mtrx);
}

int		**obtain_int_mtrx(char **str)
{
	int			line;
	const char	**cpy;
	int			cnt;
	int			**int_mtrx;
	int			*aux;

	line = 0;
	cpy = (const char **)str;
	cnt = 0;
	int_mtrx = NULL;
	while (cpy[line])
	{
		cnt += ft_count(cpy[line], ' ');
		line++;
	}
	int_mtrx = malloc(sizeof(int *) * cnt);
	line = 0;
	while (cpy[line])
	{
		aux = int_mtrx[line];
		int_mtrx[line] = str_to_int(cpy[line]);
		//str_to_int(cpy[line], int_mtrx, line);
		line++;
	}
	free(str);
	return (int_mtrx);
}

int	ft_count(char const *s, char c)
{
	int	cnt;
	size_t	bo;
	char	*a;

	cnt = 0;
	bo = 0;
	a = (char *)s;
	if (!a)
		return (0);
	while (*a)
	{
		if (*a != c && bo == 0)
		{
			cnt++;
			bo = 1;
		}
		if (*a == c)
			bo = 0;
		a++;
	}
	return (cnt);
}

int		*str_to_int(const char *str)
{
	char	**ch_aux;
	int		tmp;
	int		*i_aux;
	int		ch_len;
	int		j;

	j = 0;
	ch_aux = ft_split(str, ' ');
	while (ch_aux[j] && ch_aux[j] != '\0')
	{
		tmp = ft_atoi(ch_aux[j]);
		i_aux[j] = tmp;
		j++;
	}
	free(ch_aux);
	return (i_aux);
}
