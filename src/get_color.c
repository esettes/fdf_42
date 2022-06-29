/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:51:50 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/29 16:38:21 by iostancu         ###   ########.fr       */
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
	base = malloc(sizeof(char) * 17);
	base = "0123456789ABCDEF";
	while (base[val] != '\0')
	{
		if (base[val] == letter)
			return (val);
		val++;
	}
	//if (base)
	//	free(base);
	return (0);
}

int	str_to_color(char *color)
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
	return (color_val);
}
