/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:50:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/27 21:03:02 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define YELLOW	0xFFFF00FF
# define WHITE	0xFFFFFFFF
# define FUCSIA	0xFF00FFFF
# define BLUE	0x2060FFFF
# define PURPLE	0x8040EEFF

# define BLU_CB	0x5E4ECBFF
# define BLU_C0 0x4C50C077
# define BLU_AD 0x2C4BAEED

# define MENUDGREY 0x16161EED	/* MENU DARK BLUE-GREY */
# define MENUMGREY 0x1A1B25EE	/* menu medium dark grey */
# define MENUMLGREY 0x21232FEE	/* menu medium light dark grey */

# define CYBDBLU 0x0E1C24FF	/* cyber dark blue */
# define CYBMBLU 0x183646FF	/* cyber medium blue */
# define CYBLU 0x1F4079FF	/* cyber blue */
# define CYBLBLU 0x4D98AEFF	/* cyber light blue */
# define CYBGREY 0x718DAEFF	/* cyber grey blue */
# define CYBDRED 0x691C41FF	/* cyber dark red */
# define CYBRED 0xB12954FF	/* cyber red */
# define CYBLRED 0xCE6794FF	/* cyber light red */

# define NEOBLACK 0x181C1EED	/* neon black */
# define NEOGREEN 0x295C3AFF	/* neon green */
# define NEOLGREEN 0x66C7A6EE	/* neon light green */
# define NEOFUCSIA 0xCC3EF7EE	/* neon fucsia */
# define NEODPURP 0x462D67FF	/* neon dark purple */
# define NEOLPURP 0x737BAEFF	/* neon light purple */
# define NEOWITHE 0xC8E5EEEE	/* cneon white */

int 	menu_rgb(int value);
/**
 * Returns an hex color from red (value < 0.1) , through green,
 *  to blue (value > 0.8) 
 */
int		rgba(int value);
int		get_trgb(int str);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

#endif