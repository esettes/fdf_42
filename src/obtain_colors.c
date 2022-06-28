#include "fdf.h"

void	obtain_z_and_color(t_mtrx *m, char *str, int pos)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    char    *color;
    int		*int_mtrx;
    t_iter  iter;
    int     *int_color;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_mtrx = malloc(sizeof(int) * iter.j);
    int_color = malloc(sizeof(int) * iter.j);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        
        extract = ft_strnstr_after(ch_aux[iter.j], ",", 3);
        
        if (extract)
        {
            color = malloc(sizeof(char *)* 12);
            color = ft_memcpy(color, extract, 11);
            i_color = str_to_color(color);
            *(int_color + iter.j) = i_color;
            free (color);
        }
        else// if (!extract)
        {
            i_color = str_to_color("0x222235");
            *(int_color + iter.j) = i_color;
        }
        iter.i = ft_atoi(ch_aux[iter.j]);
		*(int_mtrx + iter.j) = iter.i;
        
        free (ch_aux[iter.j]);
		iter.j++;
        
    }
   
    m->colors[pos] = int_color;
    m->mtrx[pos] = int_mtrx;
    //free (ch_aux);
    free (str);
}


void    analize_splitted()
{
    // si strnstr(ch_aux) devuelve no nulo es que este mapa tiene color
    

}
