#include "fdf.h"

uint32_t hex2int_(char *hex) {
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

int hextodc_(char *hex)
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

void	obtain_z_and_color(t_mtrx *m, char *str, int pos)
{
    char	**ch_aux;
    char    *extract;
    char    *color;
   // char    **colors;
    long int     *int_color;
    int		*int_mtrx;
    t_iter  iter;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_mtrx = malloc(sizeof(int) * iter.j);
    int_color = malloc(sizeof(long int) * iter.j);
    //colors =malloc(sizeof(char *) * (iter.j * 220) + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        color = malloc(sizeof(char) * 11);
        extract = ft_strnstr_after(ch_aux[iter.j], "x", 4);
        if (extract)
        {
            color = ft_memcpy(color, extract, 10);
            iter.i = strtol(extract, &color, 0);
            *(int_color + iter.j) = iter.i;
            //printf("color: %s\n", color);
           // m->colors[pos][iter.j] = strtol(extract, &color, 0);
            printf ("m->colors[0][iter.j]: %li\n", m->colors[0][iter.j]);
           // colors[iter.j] = color;
            //printf("m->colors[iter.j]: %s\n", m->colors[iter.j]);
        }
        
        iter.i = ft_atoi(ch_aux[iter.j]);
		*(int_mtrx + iter.j) = iter.i;
        
		iter.j++;
        free (color);
    }
  //  printf("coolors %s\n", **colors);
    m->colors[pos] = int_color;
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
