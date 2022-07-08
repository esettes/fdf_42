/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/08 17:14:29 by iostancu         ###   ########.fr       */
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
	float	z_zoom;
	
	z_zoom = 0.5;
	start->x = (start->x - start->y) * cos(45) * 1;
	start->y = (start->x + start->y) * (sin(45) * z_zoom)  - (depth.z  *  z_zoom * (fdf->control.zoom * 0.2));
	end->x = (end->x - end->y) * cos(45) * 1;
	end->y = (end->x + end->y) * (sin(45) * z_zoom)  - (depth.z1  *  z_zoom * (fdf->control.zoom * 0.2));
	(void)fdf;
}

void	iso(t_fdf *fdf, t_vec2 *coord, int z)
{
	coord->x = ((coord->x ) - (coord->y )) * cos(45) * 1;
	coord->y = ((coord->x) + (coord->y )) * (sin(45) * 0.5)  - (z  * 0.5);
	(void)fdf;
}


int setColor(int int_color) 
{
	// if(int_color!=255)
	// printf("%d\t%x\t->",(int)int_color, (int)int_color);
	// if(int_color!=255)
	// printf("%lu\t%lx\n",int_color, int_color);
	return int_color;
}

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end, int direction)
{
	t_vec2	step;
	float step1;
	float step2;
	int		max;
	int		color;
	t_vec2	offset;
	t_depth	depth;
	t_iter	curr;
	//double	percent;
	int		p;

	curr.i = (int)start.x;
	curr.j = (int)start.y;
	
	depth.z = fdf->mtrx.mtrx[(int)start.y][(int)start.x];
	depth.z1 = fdf->mtrx.mtrx[(int)end.y][(int)end.x];
	bresen_zoom(fdf, &start, &end);
	
	offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 9);
	offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 3.5);
	
	if (fdf->control.perspective == ISOMETRIC)
		isometric(fdf, &start, &end, depth);
	start.x += fdf->control.vert;
	start.y += fdf->control.horiz;
	step.x = (float)(end.x - start.x);
	step.y = (float)(end.y - start.y);
	
	step1 = (end.x - start.x);
	step2 = (end.y - start.y);

	
	if (fdf->control.perspective == ISOMETRIC)
		max = f_max(f_mod(step.x), f_mod(step.y));
	//printf("max: %d\n", max);
	step.x /= max;
	step.y /= max;
	//printf("step x: %d, step y: %d, \n", step.x, step.y);
	//printf("\n********	in f_bresen (outer while)	********\n");
	/*while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		color = fdf->mtrx.colors[curr.j][curr.i];
		mlx_put_pixel(fdf->img, start.x + offset.x , start.y + offset.y, color);
		start.x += step.x;
		start.y += step.y;
	}*/
	
	if (direction == 0)
	{
		p = 2 * step2 - step1;
		while ((int)(start.x - end.x))// && (int)coord.x - end.x)
		{
			//printf("start x: %d, step y: %d, \n", step.x, step.y);
			color = setColor(fdf->mtrx.colors[curr.j][curr.i]);
			color = 1219892479;
			if (p > 0)
			{
				if ((end.x + offset.x < (WIDTH * IMG_AUMENT) - 100)&& (end.y + offset.y < (HEIGHT * IMG_AUMENT) - 100))
					mlx_put_pixel(fdf->img, start.x + offset.x, start.y + offset.y, color);
				//printf("\e[0;35mend.x: %i\n\e[0;37m", end.x + offset.x);
				start.y = start.y + 1;
				p = p + 2 * step2 - 2 * step1;
			}
			else
			{
				if (((end.x + offset.x + 100) < WIDTH * IMG_AUMENT) && ((end.y + offset.y + 100) < HEIGHT * IMG_AUMENT))
					mlx_put_pixel(fdf->img, start.x + offset.x, start.y + offset.y, color);
				//printf("\e[0;35mend.x: %i\n\e[0;37m", end.x + offset.x);
				p = p + 2 * step2;
			}
			start.x = start.x + 1;
		}
	}
	else
	{
		p = 2 * step1 - step2;
		while ((int)(start.x - end.x))//(coord.x > end.x)// && coord.y - end.y)
		{
			color = setColor(fdf->mtrx.colors[curr.j][curr.i]);
			color = 1219892479;
			if (p > 0)
			{
				if (((end.x + offset.x) < WIDTH * IMG_AUMENT) && ((end.y + offset.y + 100) < HEIGHT * IMG_AUMENT))
					mlx_put_pixel(fdf->img, start.x + offset.x, start.y + offset.y, color);
				//printf("\e[0;36mend.x: %i\n\e[0;37m", end.x + offset.x);
				start.y = start.y + 1;
				p = p + 2 * step2 - 2 * step1;
			}
			else
			{
				if (((end.x + offset.x + 100) < WIDTH * IMG_AUMENT) && ((end.y + offset.y + 100) < HEIGHT * IMG_AUMENT))
					mlx_put_pixel(fdf->img, start.x + offset.x, start.y + offset.y, color);
				//printf("\e[0;36mend.x: %i\n\e[0;37m", end.x + offset.x);
				p = p + 2 * step2;
			}
			start.x = start.x - 1;
		}
	}
}

