/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:27:36 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 21:56:50 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

typedef struct str
{
	char	*nbr;
	char	*word;
}			t_str;

int			ft_rm_chars(char *nbr, int n);
char		*ft_rm_zero(char *nbr);
int			ft_is_alpha(char c);
int			ft_is_num(char c);
int			ft_n_of_lines(int file);
int			ft_len(char *str);
char		*ft_strcpy(char *dest, char *src);
void		ft_strlcpy(char *dest, char *src, unsigned int size);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr(char *str);
void		ft_free_all(struct str *dict, int nlines, char *nbr);

#endif
