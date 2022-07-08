#include "fdf.h"

void	obtain_z_and_color(t_mtrx *m, char *str, int pos)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    int		*int_mtrx;
    t_iter  iter;
    t_iter  aux;
    int     *int_color;
    //int     def_color;

    iter.i = 0;
    iter.j = 0;
    // printf("%s\n",str);
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_mtrx = malloc(sizeof(int) * iter.j + 1);
    int_color = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
    //def_color = str_to_color("89ED2A");
	while (ch_aux[iter.j])
    {
        //extract = ft_strnstr_after(ch_aux[iter.j], "x", 5);
        extract = ft_strchr(ch_aux[iter.j], 'x');
        
        // si la extraccion es distinta de lo que ya hay en la cadena entonces calcular, sino continuar
        if (extract)// && extract != "")
        {
            extract++;
            //printf("\e[2;33mextract++:\t%s\n\e[0;37m",extract);
            i_color = str_to_color(extract);
            ///i_color = ft_atoi_base(extract, 16);
            *(int_color + iter.j) = i_color;
            //printf("Hola\n");
            extract = ""; 
        }
        //else
        //  *(int_color + iter.j) = def_color;
        
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

// funcion que detecta altura de la z y devuelve un color acorde
//unsigned int    color_for_z(int z)