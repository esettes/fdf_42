/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:51:50 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/01 21:31:51 by iostancu         ###   ########.fr       */
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
	int		int_color;
	char	*aux;
	t_iter	iter;
	size_t	i;

	//iter.i = ft_strlen(color) - 1;
	aux = ft_strnstr_after(color, "x", 2);
	iter.i = 0;
	iter.j = 0;
	i = ft_strlen(aux) - 1;
	int_color = 0;
	//printf("\e[1;35m----------color: %s\n\e[0;37m", aux);
	
	/* se coge el primer char despues de '0x' y se multiplica por la ultima pos de un hex(7)*/
	while (ft_isalnum(aux[iter.i]))
	{
		//printf("\e[2;33m -inwhile- color[%i]: %c\n\e[0;37m", iter.i, aux[iter.i]);
		if (aux[iter.i] == '\0' || aux[iter.i] == 'x')
			break ;
		iter.j = char_to_int(aux[iter.i]);
		//printf("hex value: %i\n", iter.j);
		iter.j = iter.j << (i * sizeof(int));
		int_color = int_color | iter.j;
		i--;
		iter.i++;
		
	}
	// rellenar con 0 el resto de posiciones que quedan
	/*while (i >= 2)
	{
		char z = '0';
		iter.j = char_to_int(z, i);
		iter.j = iter.j << (i * sizeof(int));
		int_color = int_color | iter.j;
		i--;
	}*/
	//printf("\e[1;32mint_color: %i\n\e[0;37m", int_color);
	return (int_color);
}

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