/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/28 20:40:24 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresen_zoom(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x *= fdf->control.zoom;
	start->y *= fdf->control.zoom;
	end->x *= fdf->control.zoom;
	end->y *= fdf->control.zoom;
}

float	f_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	f_mod(float a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}


void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)//, t_vec2 *end, t_depth dep)
{
	start->x = (start->x - start->y) * cos(0.8);
	start->y = (start->x + start->y) * sin(0.8) - depth.z;
	end->x = (end->x - end->y) * cos(0.8);
	end->y = (end->x + end->y) * sin(0.8) - depth.z;
	(void)fdf;
}

void	iso(t_fdf *fdf, t_vec2 *coord, int z)
{
	
	coord->x = ((coord->x ) - (coord->y )) * cos(45) * 1;
	coord->y = ((coord->x) + (coord->y )) * (sin(45) * 0.5)  - (z  * 0.5);
	(void)fdf;
}
uint32_t hex2int(char *hex) {
    uint32_t val = 0;
    while (*hex) {
        // get current character then increment
        uint8_t byte = *hex++; 
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;    
        // shift 4 to make space for new digit, and add the 4 bits of the new digit 
        val = (val << 4) | (byte & 0xF);
    }
    return val;
}
int hextodc(char *hex)
{
   int y = 0;
   int dec = 0;
   int x, i;
   for(i = strlen(hex) - 1 ; i >= 0 ; --i)
   {
      if(hex[i]>='0'&&hex[i]<='9'){
         x = hex[i] - '0';
      }
      else{
         x = hex[i] - 'A' + 10;
      }
      dec = dec + x * pow(16 , y);// converting hexadecimal to integer value ++y;
   }
   return dec;
}

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end)
{
	t_vec2	step;
	int		max;
	t_vec2	offset;
	t_depth	depth;
	t_vec2	aux;
	int		**z_mesh;
	int		color;

	z_mesh = fdf->mtrx.mtrx;
	aux = start;
	depth.z = z_mesh[(int)start.y][(int)start.x];
	depth.z1 = z_mesh[(int)end.y][(int)end.x];
	bresen_zoom(fdf, &start, &end);
	if (depth.z > 11)
		color = 0x718DAEFF;
	else if (depth.z > 9)
		color = BLU_CB;
	else if (depth.z > 7)
		color = 0x1F4079FF;
	else if (depth.z > 5)
		color = 0x183646FF;
	else if (depth.z >= 1)
		color = 0x0E1C24FF;
	else
		color = 0x00000012;
	
	offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 6);
	offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 4);
	
	//isometric(fdf, &start, &end, depth);
	iso(fdf, &start, depth.z);
	iso(fdf, &end, depth.z1);
	step.x = end.x - start.x;
	step.y = end.y - start.y;
	max = f_max(f_mod(step.x), f_mod(step.y));
//	start.x += IMG_CENTER_X / 2;
//	start.y += IMG_CENTER_Y / 2;
//	end.x += IMG_CENTER_X / 2;
//	end.y += IMG_CENTER_Y / 2;
	step.x /= max;
	step.y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		
		mlx_put_pixel(fdf->img, start.x + offset.x, start.y + offset.y, 
			fdf->mtrx.colors[(int)aux.x][(int)aux.y]);
		//printf ("fdf->mtrx.colors[(int)start.x][(int)start.y]: %i\n",fdf->mtrx.colors[(int)start.x][(int)start.y]);
		//printf("offset x: %f, y: %f\n", offset.x, offset.y);
		//printf("start x: %f, y: %f\n", start.x, start.y);
		start.x += step.x;
		start.y += step.y;
	}
}