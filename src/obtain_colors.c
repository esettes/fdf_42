#include "fdf.h"

void	obtain_z_and_color(t_mtrx *m, char *str, int pos, int size)
{
    char	**ch_aux;
    char    *extract;
    char    *color;
    int		*int_mtrx;
    //char    *cpy;
    t_iter  iter;


    //cpy = malloc(sizeof(char *) * size + 1);
    //*cpy = *str;
    if (size > 0)
        puts("ok");
    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_mtrx = malloc(sizeof(int) * iter.j);
    iter.j = 0;
    
	while (ch_aux[iter.j])
    {
        color = malloc(sizeof(char) * 11);
        extract = ft_strnstr_after(ch_aux[iter.j], ",", 4);
        if (extract)
        {
            color = ft_memcpy(color, extract, 10);
            //printf("color: %s\n", color);
            m->colors[iter.j] = color;
            //printf("m->colors[iter.j]: %s\n", m->colors[iter.j]);
        }
        iter.i = ft_atoi(ch_aux[iter.j]);
		*(int_mtrx + iter.j) = iter.i;
		iter.j++;
        free (color);
    }
    m->mtrx[pos] = int_mtrx;
    free (ch_aux);
    free (str);
}

void    analize_splitted()
{
    // si strnstr(ch_aux) devuelve no nulo es que este mapa tiene color
    

}

//char	*str_to_color(char *str)
//{
 //   return (0);
//}
