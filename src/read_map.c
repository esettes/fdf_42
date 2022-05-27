/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/27 23:19:33 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_alloc_mtx(int fd)
{
	char	*mp;
	char	*map_line;
	int		**mtrx;
	int		i;
	int		j;

	i = 0;
	mp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	mp = read_fd(fd, mp);
	if (!mp)
		return (NULL);
	while (mp[i] != '\n')
		i++;
	map_line = malloc(sizeof(char) * (i + 1));
	//map = ft_split(mp, '\n');
	//free(mp);
	i = 0;
	while (mp[i])
	{
		j = 0;
		while (mp[i] != '\n')
		{
			map_line[j++] = mp[i++];
		}
		
		i++;
	}
	// como no funciona, tratar de reservar menos memoria, ahora debería llamar directamente
	// str_to_int, allí también debería medir la 2ª dimension del int_mtrx, contando las
	//líneas que tiene mp (ya que aquí no me caben mas variables)
	//mtrx = obtain_int_mtrx(map);
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
		aux = str_to_int(cpy[line]);
		int_mtrx[line] = aux;
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

int		*str_to_int(char *str)
{
	char	**ch_aux;
	int		tmp;
	int		**int_mtrx;
	int		j;

	j = 0;
	ch_aux = ft_split(str, ' ');
	while (*(str + j) && ft_isdigit(*(str + j)))
		j++;
	int_mtrx = malloc(sizeof(int) * j);
	j = 0;
	while (ch_aux[j] && ch_aux[j] != '\0')
	{
		tmp = ft_atoi(ch_aux[j]);
		int_mtrx[j] = tmp;
		j++;
	}
	free(ch_aux);
	return (int_mtrx);
}
