/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:27:02 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/04 01:10:53 by iostancu         ###   ########.fr       */
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
		return (NEOFUCSIA);
	if (value < 0.5)
		return (NEOLGREEN);
	else
		return (NEOWITHE);
}