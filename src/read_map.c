/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/30 20:55:44 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	print_matrix(int **mtrx)
// {
// 	int	i = 0;
// 	int	j = 0;

// 	while (mtrx[i] != '\0')
// 	{
// 		j = 0;
// 		while (mtrx[i][j] != '\0')
// 		{
// 			printf("%i ", mtrx[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

int	**obtain_split_fd(int fd)
{
	char	**split_fd;
	int		**mtrx;
	int		i;
	int j	 = 0;
	int		count;

	split_fd = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	i = 0;
	count = 0;
	while (true)
	{
		split_fd[i] = get_next_line(fd);
		count += ft_count(split_fd[i], ' ');
		if (split_fd[i] == NULL)
			break ;
		i++;
	}
	mtrx = malloc(sizeof(int *) * count);
	i = 0;
	while (split_fd[i])
	{
		mtrx[i] = str_to_int(split_fd[i]);
		j = 0;
		while (j < count/10)
		{
			printf("%i ", mtrx[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (mtrx);
}

/*
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

int		*str_to_int(char *str)
{
	char	**ch_aux;
	int		tmp;
	int		*int_mtrx;
	int		j;
	int		aux;

	j = 0;
	ch_aux = ft_split(str, ' ');
	while (ch_aux[j])
		j++;
	int_mtrx = malloc(sizeof(int) * j);
	aux = j;
	j = 0;
	while (ch_aux[j])
	{
		tmp = ft_atoi(ch_aux[j]);
		*(int_mtrx + j)= tmp;
		j++;
	}
	free (str);
	free(ch_aux);
	return (int_mtrx);
}
