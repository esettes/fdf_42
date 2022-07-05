/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:51:50 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/05 19:56:20 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int	get_trgb(int str)
{
	int	color[4];
	
	color[0] = get_r(str);
	color[1] = get_g(str);
	color[2] = get_b(str);
	return (color);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}*/

/*
"0123456789abcdef"

1 2 4 8 16 32 64 128 256 512 1024 2048 4096 

8 4 2 1
0 0 0 0

15
1111 = 8+4+2+1

0010 2
0011 3
0100 4
1011 11

6 0110
12 1100


0000 0000  0000 0000  0000 0000  0000 0000 

f0f5 = f0f50000

f = 11111 = 15

*/
void	init_rgba(t_rgba *rgba)
{
	rgba->r = 0;
	rgba->g = 0;
	rgba->b = 0;
	rgba->a = 255;
}

int		char_to_int(char c)
{
	size_t	trigger;
	char	*hex;
	char	*hex2;
	t_iter	iter;
	
	//printf("pos: %i\n", pos);
	//printf("char: %c\n", c);
	iter.i = 0;
	trigger = FALSE;
	hex = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	if (!c)
	 	return (iter.i);
	while (hex[iter.i])
	{
		if (c == hex[iter.i])
		{
			trigger = TRUE;
			return (iter.i);
		}
		iter.i++;
	}
	iter.i = 0;
	if (trigger == FALSE)
	{
		while (hex2[iter.i])
		{
			if (c == hex2[iter.i])
				return (iter.i);
			iter.i++;
		}
	}
	return (iter.i);
}

int		str_to_color(char *color)
{
	unsigned long		int_color;
	char	*aux;
	t_rgba	rgba;
	t_iter	iter;
	t_uiter	uiter;
	t_iter	save;
	size_t	i;

	aux = color;
	init_rgba(&rgba);
	iter.i = 0;
	iter.j = 1;
	uiter.a = 0;
	uiter.b = 1;
	i = ft_strlen(color) - 1;
	int_color = 0;
	while (i >= 0)
	{
		//printf("\e[2;33m -inwhile- color[%i]: %c\n\e[0;37m", iter.i, aux[iter.i]);
		if ( aux[iter.i] == 'x' || aux[iter.i] == '\0')
			break ;
		uiter.b = char_to_int(aux[iter.i]);
		//printf("\e[2;37mi:\t%i\n\e[0;37m", i);
		if (i % 2 == 0)
		{
			save.j = uiter.b; // solo para prueba, eliminar luego
			uiter.b = save.i * uiter.b;
			if (i == 4) // hay r,g y b y hay que guardar el red
			{
				//printf("\e[2;31msave: %i, uiter.b: %i\e\n[0;37m", save.i, save.j);
				rgba.r = uiter.b;
				//printf("\e[0;31mr:\t%i, \e[0;37m", rgba.r);
			}
			if (i == 2) // hay g y b y hay que guardar el green
			{
				rgba.g = uiter.b;
				//printf("\e[0;32mg:\t%i, \e[0;37m", rgba.g);
			}
			if (i == 0) // hay b y hay que guardar el blue
			{
				rgba.b = uiter.b;
				//printf("\e[0;34mb:\t%i\n\e[0;37m", rgba.b);
			}
		}
		save.i = uiter.b;
		//iter.j = iter.j << (i * 4);
		//int_color = int_color | iter.j;
		i--;
		iter.i++;
	}
	//printf("\e[0;37ma:\t%i\n\e[0;37m", rgba.a);
	int_color = separate_sections(rgba.r, rgba.g, rgba.b, rgba.a);
	//printf("\e[2;33mint_color:\t%i\n\n\e[0;37m", int_color);
	//printf("\e[2;33mint_color before separate_section:  %i\n\e[0;37m", int_color);
	//int_color = separate_sections(int_color);
	
	return (int_color);
}

// char	*parse_color(char *original)
// {
// 	char	*transform;
// 	t_iter	iter;
// 	size_t	len;

// 	iter.i = 0;
// 	len = ft_strlen(original);
// 	// si tiene 2, añadir r, g y alpha
// 	// si tiene 4, añadir r y alpha
// 	// si tiene 6, añadir alpha
// 	if (len == 2)
// 	{
// 		while (ft_isalnum(original[iter.i]))
// 		{
// 			// hacer 2 veces str_to_int y despues (hexvalue & 0xFF) / 255
// 		}
// 	}
// }

/*
pos = 7


color = 0
// color = 0000 0000  0000 0000  0000 0000  0000 0000 

f -> 1111

c = 15
// c = 0000 0000  0000 0000  0000 0000  0000 1111 

c = c << (pos * 4)
// c = 1111 0000  0000 0000  0000 0000  0000 0000 

color = color | c
//         0000 0000  0000 0000  0000 0000  0000 0000 
//         1111 0000  0000 0000  0000 0000  0000 0000 
// color = 1111 0000  0000 0000  0000 0000  0000 0000 

pos--

// Siguiente char
0 -> 0000

c = 0
// c = 0000 0000  0000 0000  0000 0000  0000 0000 

c = c << (pos * 4)
// c = 0000 0000  0000 0000  0000 0000  0000 0000 

color = color | c
//         1111 0000  0000 0000  0000 0000  0000 0000 
//         0000 0000  0000 0000  0000 0000  0000 0000 
// color = 1111 0000  0000 0000  0000 0000  0000 0000 

pos--

// Siguiente char
f -> 1111

c = 15
// c = 0000 0000  0000 0000  0000 0000  0000 1111 

c = c << (pos * 4)
// c = 0000 0000  1111 0000  0000 0000  0000 0000 

color = color | c
//         1111 0000  0000 0000  0000 0000  0000 0000 
//         0000 0000  1111 0000  0000 0000  0000 0000 
// color = 1111 0000  1111 0000  0000 0000  0000 0000 

pos--

// Siguiente char
5 -> 0101

c = 5
// c = 0000 0000  0000 0000  0000 0000  0000 0101

c = c << (pos * 4)
// c = 0000 0000  0000 0101  0000 0000  0000 0000 

color = color | c
//         1111 0000  1111 0000  0000 0000  0000 0000 
//         0000 0000  0000 0101  0000 0000  0000 0000 
// color = 1111 0000  1111 0101  0000 0000  0000 0000 

pos--
*/