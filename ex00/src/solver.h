/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:13:48 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 20:55:52 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "utility.h"

void	ft_print_num(char *nbr, struct str *dict, int nlines);
void	ft_print_two(char *nbr, struct str *dict, int nlines);
void	ft_print_three(char *nbr, struct str *dict, int nlines);
char	*ft_build_nbr(int size);
int		solve(char *nbr, struct str *dict, int nlines);
int		ft_print_position(char *nbr, struct str *dict, int nlines, int mod);
int		ft_remove_by_mod(char *nbr);

#endif