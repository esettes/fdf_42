/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/15 17:16:48 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	obtain_split_fd(int fd, t_mtrx *m)
{
	char	**split_fd;
	int		**mtrx;
	int		i;
	int		aux;
	int j	 = 0;
	int		count;
	int		trigger = TRUE;

	split_fd = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	i = 0;
	count = 0;
	while (true)
	{
		split_fd[i] = get_next_line(fd);	// i = y 
		count += ft_count(split_fd[i], ' ');
		if (trigger == TRUE)
		{
			aux = count;
			trigger = FALSE;
		}
		if (split_fd[i] == NULL || ft_strncmp(split_fd[i], "\n", 1) == 0 || 
			ft_strncmp(split_fd[i], " ", 1) == 0)
			break ;
		i++;
	}
	m->segments = set_mtrx_size(aux, i, m);
	//set_limits(m);
	mtrx = malloc(sizeof(int *) * count);
	printf("\nm->size->y: %f \n", m->segments.y);
	printf("m->size->x: %f \n\n", m->segments.x);
	i = 0;
	while (split_fd[i])
	{
		mtrx[i] = str_to_int(split_fd[i]);
		j = 0;
		while (j < count/m->segments.y)
		{
			printf("%i ", mtrx[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	m->mtrx = mtrx;
	i = 0;
	//free (mtrx);
	//return (mtrx);
}

int	ft_count(char const *s, char c)
{
	int	cnt;
	size_t	bo;
	char	*a;

	cnt = 0;
	bo = 0;
	if (!s)
		return (0);
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

int	*str_to_int(char *str)
{
	char	**ch_aux;
	int		tmp;
	int		*int_mtrx;
	int		j;

	j = 0;
	ch_aux = ft_split(str, ' ');
	while (ch_aux[j])
		j++;
	int_mtrx = malloc(sizeof(int) * j);
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
