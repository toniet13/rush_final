/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:05:41 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 21:57:31 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "utility.h"

char	*ft_get_wrd(char *nbr, t_str *dict, int nlines);
int		mem_alloc(t_str *dict, int nlines);
void	dict_init(t_str *dict, int file, int nlines);
void	read_nbr(t_str *dict, int file, char *temp, int i);
void	read_wrd(t_str *dict, int file, char *temp, int i);

#endif