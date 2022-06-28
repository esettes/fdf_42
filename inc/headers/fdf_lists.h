/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lists.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:50:47 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/28 19:52:29 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LISTS_H
# define FDF_LISTS_H

#include "structs.h"

t_point	*fdf_lstnew(void *color);
void	fdf_lstadd_back(t_point **lst, t_point *new);

#endif