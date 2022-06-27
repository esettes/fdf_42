/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 04:09:28 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_fd_end(char *s);

void	obtain_split_fd(int fd, t_mtrx *m)
{
	char	**split_fd;
	t_iter	iter;
	int		aux;
	int		trigger = TRUE;

	split_fd = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	iter.i = 0;
	iter.j = 0;
	while (true)
	{
		split_fd[iter.i] = get_next_line(fd);	// i = y 
		
		/* put here a function that saves in an array colors of each value*/
		
		iter.j += ft_count(split_fd[iter.i], ' ');
		if (trigger == TRUE)
		{
			aux = iter.j;
			trigger = FALSE;
		}
		if (check_fd_end(split_fd[iter.i]))
			break ;
		iter.i++;
	}
	m->vertices = set_mtrx_size(aux, iter.i);
	m->mtrx = malloc(sizeof(int *) * iter.j);
	m->colors = malloc(sizeof(char *) * iter.j + 1);
	printf("\nm->size->y: %f \n", m->vertices.y);
	printf("m->size->x: %f \n\n", m->vertices.x);
	iter.i = 0;
	
	while (split_fd[iter.i])
	{
		obtain_z_and_color(m, split_fd[iter.i], iter.i, iter.j);
		iter.i++;
	}
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
	t_iter	iter;
	int		*int_mtrx;

	iter.j = 0;
	ch_aux = ft_split(str, ' ');
	analize_splitted();
	while (ch_aux[iter.j])
		iter.j++;
	int_mtrx = malloc(sizeof(int) * iter.j);
	iter.j = 0;
	while (ch_aux[iter.j])
	{
		iter.i = ft_atoi(ch_aux[iter.j]);
		*(int_mtrx + iter.j) = iter.i;
		iter.j++;
	}
	free (str);
	free(ch_aux);
	return (int_mtrx);
}

int	check_fd_end(char *s)
{
	if (s == NULL || ft_strncmp(s, "\n", 1) == 0 || 
		ft_strncmp(s, " ", 1) == 0)
		return (TRUE);
	else
		return (FALSE);
}

