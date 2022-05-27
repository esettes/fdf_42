/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/27 21:01:57 by iostancu         ###   ########.fr       */
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
	int			lines;
	const char	**cpy;
	int			**m;
	int			count;
	int			**aux;

	lines = 0;
	cpy = (const char **)str;
	free(str);
	count = 0;
	while (cpy[lines])
	{
		count += ft_count(cpy[lines], ' ');// - 1; // resto 1 por el \n
		lines++;
	}
	// mtrx->size->x = count/lines;
	// mtrx->size->y = lines;
	//m = (malloc(sizeof(int *) * (count + 1)));
	m = ft_calloc(count, 4);
	lines = 0;
	count = 0;
	while (cpy[lines])
	{
		
		aux = str_to_int(aux);
		if (ft_isdigit(cpy[lines][count] != ' ')
			m[lines][count] = ft_atoi(cpy[lines][count]);
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

int		*str_to_int(char *str)
{
	char	**ch_aux;
	char	*tmp;
	int		*int_aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ch_aux = ft_split(str, ' ');
	while (ch_aux[j] && ch_aux[j] != '\0')
	{
		tmp = ft_strtrim(ch_aux, '\n');
		int_aux[j] = ft_atoi(tmp);
		free(tmp);
		j++;
	}
	int_aux[j] = '\0';
	free(ch_aux);
	return (int_aux);
}
