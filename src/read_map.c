/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/30 19:12:40 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**obtain_split_fd(int fd)
{
	char	**split_fd;
	int		**mtrx;
	int		i;
	int		j;
	int		first_line_nums;

	split_fd = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	i = 0;
	first_line_nums = ft_count(split_fd[i], ' ') - 1;
	mtrx = malloc(sizeof(int *) * (first_line_nums));
	while (true)
	{
		split_fd[i] = get_next_line(fd);
		if (split_fd[i] == NULL)
			break ;
		mtrx[i] = str_to_int(split_fd[i], first_line_nums);
		if (mtrx[i] == NULL)
			printf ("El número de integers no coincide!");
		i++;
	}
	j = i;
	i = 0;
	while (i < j)
	{
		printf("%s", split_fd[i]);
		i++;
	}
	return (split_fd);
}

/*char	**obtain_lines(int fd)
{
	char	*mp;
	char	**map_line;
	int		i;
	int		j;
	int 	k;

	i = 0;
	k = 0;
	mp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	mp = read_fd(fd, mp);
	if (!mp)
		return (NULL);
	while (mp[i] != '\0')
		i++;
	map_line = malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (mp[i] != '\0' && mp[i] != '\n')
	{
		map_line[k][j++] = mp[i++];
		i++;
		if (mp[i] == '\n')
		{
			k++;
			i++;
		}
	}
	// como no funciona, tratar de reservar menos memoria, ahora debería llamar directamente
	// str_to_int, allí también debería medir la 2ª dimension del int_mtrx, contando las
	//líneas que tiene mp (ya que aquí no me caben mas variables)
	//mtrx = obtain_int_mtrx(map);
	return (map_line);
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
}*/

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


int		*str_to_int(char *str, int n)
{
	char	**ch_aux;
	int		tmp;
	int		*int_mtrx;
	int		j;

	j = 0;
	ch_aux = ft_split(str, ' ');
	while (ch_aux[j])
		j++;
	if (j != n)
		return (NULL);
	int_mtrx = malloc(sizeof(int) * j);
	j = 0;
	while (ch_aux[j])
	{
		tmp = ft_atoi(ch_aux[j]);
		int_mtrx[j] = tmp;
		j++;
	}
	free (str);
	free(ch_aux);
	return (int_mtrx);
}
