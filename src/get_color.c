/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:51:50 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/30 20:23:03 by iostancu         ###   ########.fr       */
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

char	*color_format(char *color)
{
	int		color_str_len;
	int		j;
	int		i;
	char	*color_hex;

	j = 2;
	i = 0;
	color_str_len = ft_strlen(color);
	color_hex = malloc(sizeof (char) * 7);
	while (j < color_str_len)
	{
		color_hex[i] = color[j];
		i++;
		j++;
	}
	color_hex[6] = '\0';
	return (color_hex);
}


int	letter_value(char letter)
{
	char	*base;
	int		val;

	val = 0;
	//base = malloc(sizeof(char) * 17);
	base = "0123456789ABCDEF";
	while (base[val] != '\0')
	{
		if (base[val] == letter)
			return (val);
		val++;
	}
	//if (base)
	//free(base);
	return (0);
}

int	str_to_color_(char *color)
{
	int		color_len;
	int		exp;
	int		color_val;
	int		letter_val;
	int		nb_exp;

	color = color_format(color);
	color_val = 0;
	color_len = ft_strlen(color);
	exp = 0;
	while (color_len > 0)
	{
		color_len--;
		letter_val = letter_value(color[color_len]);
		nb_exp = pow(16, exp);
		color_val += (letter_val * nb_exp);
		exp++;
	}
	free(color);
	return (color_val);
}

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

int		char_to_int(char c, int pos)
{
	char	*aux;
	size_t	val;
	
	printf("aux: %c\n", c);
	aux = ft_strnstr(HEX_L, &c, pos + 1);
	if (!aux)
	{
		aux = ft_strnstr(HEX_U, &c, pos + 1);
		if (!aux)
			return (FALSE);
	}
	val = 16 - ft_strlen(aux);
	printf("val: %zu\n", val);
	return (val);
}

int		str_to_color(char *color)
{
	int		int_color;
	char	*aux;
	t_iter	iter;

	aux = color;
	iter.i = 0;
	int_color = 0;
	while (aux[iter.i])
	{
		if (aux[iter.i] != '0' && aux[iter.i] != 'x')
		{
			iter.j = char_to_int(aux[iter.i], iter.i);
			printf("iter.j: %i\n", iter.j);
			iter.j = iter.j << (iter.i * sizeof(int));
			int_color = int_color | iter.j;
			printf("int_color: %i\n", int_color);
		}
		iter.i++;
	}
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