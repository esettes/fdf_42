/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:48:09 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/28 19:58:46 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*fdf_lstlast(t_point *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


void	fdf_lstadd_back(t_point **lst, t_point *new)
{
	t_point	*t;

	t = fdf_lstlast(*lst);
	if (t)
	{
		t->color = new->color;
		t->next = new;
	}
	else
		*lst = new;
}

t_point	*fdf_lstnew(void *color)
{
	t_point	*lst;

	lst = (t_point *)malloc(sizeof(t_point));
	if (!lst)
		return (NULL);
	lst->color = (int)color;
	lst->next = NULL;
	return (lst);
}
