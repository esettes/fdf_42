/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:29:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 03:10:27 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWS_H
# define VIEWS_H

# include "structs.h"

void	view_on_top(t_fdf *fdf);
void	test_view_iso(t_fdf *fdf);
void	new_view_iso(t_fdf *fdf);

void	new_view_iso_testing(t_fdf *fdf);
void	line_horiz(t_vec2 coord, t_fdf *fdf);
void	line_vert(t_vec2 coord, t_fdf *fdf);

t_depth	set_depth(t_fdf *fdf);//, t_vec2 coord);
void	zoom(t_fdf *fdf);

float	f_max(float a, float b);
float	f_mod(float a);
void	bresen_put_pixel(t_fdf *fdf, t_vec2 step);

#endif