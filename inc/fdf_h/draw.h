/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:25:48 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 12:33:03 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "structs.h"

void	draw_outer_segments(t_fdf *fdf);
void	test_draw_iso(t_fdf *fdf);
void	draw_segment_horiz(t_vec2 start, t_vec2 end, t_fdf *fdf, double color);
void	draw_segment_vert(t_vec2 start, t_vec2 end, t_fdf *fdf, double color);
void	draw_segment_negative(t_vec2 start, t_vec2 end, t_fdf *fdf, double color);
void	draw_menu(t_fdf *fdf);
void	print_box_menu(t_fdf fdf, int color, int max_x, int max_y);

#endif