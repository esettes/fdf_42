/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/20 23:05:29 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_mtx	*mtx)
{
	
}

char	**ft_alloc_map(int fd)
{
	char	*mp;
	char	**map;

	mp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	mp = read_fd(fd, mp);
	map = ft_split(mp, '\n');
	free(mp);
	return (map);
}
