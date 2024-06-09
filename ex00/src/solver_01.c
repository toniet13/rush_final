/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:16:44 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 18:17:01 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "solver.h"
#include "utility.h"

void	ft_print_two(char *nbr, t_str *dict, int nlines)
{
	char	temp[3];

	if (nbr[0] == '1')
		ft_putstr(ft_get_wrd(nbr, dict, nlines));
	else if (nbr[1] == '0')
		ft_putstr(ft_get_wrd(nbr, dict, nlines));
	else
	{
		if (nbr[0] != '0')
		{
			temp[0] = nbr[0];
			temp[1] = '0';
			temp[2] = '\0';
			ft_putstr(ft_get_wrd(temp, dict, nlines));
		}
		temp[0] = nbr[1];
		temp[1] = '\0';
		ft_print_num(temp, dict, nlines);
	}
}

void	ft_print_three(char *nbr, t_str *dict, int nlines)
{
	char	temp[3];

	if (nbr[1] == '0' && nbr[2] == '0')
	{
		if (nbr[0] != '0')
		{
			ft_strlcpy(temp, nbr, 1);
			ft_putstr(ft_get_wrd(temp, dict, nlines));
			ft_putstr(ft_get_wrd("100", dict, nlines));
		}
	}
	else
	{
		if (nbr[0] != '0')
		{
			ft_strlcpy(temp, nbr, 1);
			ft_putstr(ft_get_wrd(temp, dict, nlines));
			ft_putstr(ft_get_wrd("100", dict, nlines));
		}
		temp[0] = nbr[1];
		temp[1] = nbr[2];
		temp[2] = '\0';
		ft_print_num(temp, dict, nlines);
	}
}

void	ft_print_num(char *nbr, t_str *dict, int nlines)
{
	if (ft_len(nbr) == 1)
		ft_putstr(ft_get_wrd(nbr, dict, nlines));
	else if (ft_len(nbr) == 2)
		ft_print_two(nbr, dict, nlines);
	else
		ft_print_three(nbr, dict, nlines);
}
