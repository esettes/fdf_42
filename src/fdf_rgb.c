/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:27:02 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/03 23:28:16 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgba(double value)
{
	if (value < 0.1)
		return (BLU_AD);
	if (value < 0.5)
		return (FUCSIA);
	if (value < 1)
		return (YELLOW);
}