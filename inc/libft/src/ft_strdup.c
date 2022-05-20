/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:20:53 by iostancu          #+#    #+#             */
/*   Updated: 2022/05/18 20:38:54 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}
