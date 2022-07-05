#include "fdf.h"

void	obtain_z_and_color(t_mtrx *m, char *str, int pos)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    int		*int_mtrx;
    t_iter  iter;
    int     *int_color;

    iter.i = 0;
    iter.j = 0;
    // printf("%s\n",str);
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_mtrx = malloc(sizeof(int) * iter.j + 1);
    int_color = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        //extract = ft_strnstr_after(ch_aux[iter.j], "x", 5);
        extract = ft_strchr(ch_aux[iter.j], 'x');
        

        if (extract)// && extract != "")
        {
            extract++;
            //printf("\e[2;33mextract++:\t%s\n\e[0;37m",extract);
            i_color = str_to_color(extract);
            ///i_color = ft_atoi_base(extract, 16);
            *(int_color + iter.j) = i_color;
            // printf("Hola\n");
        }
        else
           *(int_color + iter.j) = str_to_color("89ED2A");
        extract = ""; 
        iter.i = ft_atoi(ch_aux[iter.j]);
		*(int_mtrx + iter.j) = iter.i;
		iter.j++;
    }
   
    m->colors[pos] = int_color;
    m->mtrx[pos] = int_mtrx;
    if (ch_aux)
        free (ch_aux);
    free (str);
}
