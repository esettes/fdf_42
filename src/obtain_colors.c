#include "fdf.h"

void	obtain_z_and_color(t_mtrx *m, char *str, int pos, int size)
{
    char    *cpy;

    cpy = malloc(sizeof(char *) * size + 1);
    *cpy = *str;
    m->mtrx[pos] = str_to_int(str);

}

void    analize_splitted()
{
    // si strnstr(ch_aux) devuelve algo (no nulo) es que este mapa tiene color
    

}

char	*str_to_color(char *str)
{
    return (0);
}
