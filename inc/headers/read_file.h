/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:07:08 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/20 13:08:19 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# include "structs.h"

char	**obtain_lines(int fd);
/**
 * Receives the previously opened fd, which is to be converted to a double
 * pointer array and stored in *m.
 * 
 * @param[in] fd File already open.
 * @param[in] m Struct where the conversion will be saved.
 */
void	obtain_split_fd(int fd, t_mtrx *m);
/**
 * Returns the number words of *s separated by 'c'
 */
int		ft_count(char const *s, char c);
/**
 * Returns the conversion of *str to an integer string
 */
int		*str_to_int(char *str);

#endif