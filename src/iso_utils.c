#include "fdf.h"

void	zoom(t_fdf *fdf)
{
	fdf->mtrx.start.x *= fdf->mtrx.control.zoom;
	fdf->mtrx.start.y *= fdf->mtrx.control.zoom;
	fdf->mtrx.end.x *= fdf->mtrx.control.zoom;
	fdf->mtrx.end.y *= fdf->mtrx.control.zoom;
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

void	line_horiz(t_vec2 coord, t_fdf *fdf)
{
	fdf->mtrx.start.x += coord.x;
	fdf->mtrx.start.y += coord.y;
	fdf->mtrx.end.x += coord.x + 1;
	fdf->mtrx.end.y += coord.y;
    fdf->mtrx.current.x += coord.x;
	fdf->mtrx.current.y += coord.y;
	fdf->mtrx.next.x += coord.x + 1;
	fdf->mtrx.next.y += coord.y;
}

void	line_vert(t_vec2 coord, t_fdf *fdf)
{
	fdf->mtrx.start.x += coord.x;
	fdf->mtrx.start.y += coord.y;
    fdf->mtrx.end.x += coord.x;
	fdf->mtrx.end.y += coord.y + 1;
    fdf->mtrx.current.x += coord.x;
	fdf->mtrx.current.y += coord.y;
	fdf->mtrx.next.x += coord.x;
	fdf->mtrx.next.y += coord.y + 1;
}