/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:27:02 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/14 19:36:17 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int menu_rgb(int value)
{
	if (value == 0)
		return (MENUDGREY);
	if (value == 1)
		return (MENUMGREY);
	else
		return (MENUMLGREY);
}

int	rgba(double value)
{
	if (value < 0.1)
		return (BLU_CB);
	if (value < 0.5)
		return (CYBRED);
	else
		return (NEOWITHE);
}