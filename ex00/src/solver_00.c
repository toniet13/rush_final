/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:14:51 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 21:56:44 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "solver.h"
#include "utility.h"
#include <stdlib.h>

char	*ft_build_nbr(int size)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * size);
	if (ret == NULL)
		return (NULL);
	i = 1;
	ret[0] = '1';
	while (i < size)
	{
		ret[i] = '0';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_print_position(char *nbr, t_str *dict, int nlines, int mod)
{
	char	*build;
	int		i;

	if (mod == 0)
		i = 2;
	else if (mod == 1)
		i = 0;
	else
		i = 1;
	build = ft_build_nbr(ft_len(nbr) - i);
	if (build == NULL)
		return (0);
	ft_putstr(ft_get_wrd(build, dict, nlines));
	free(build);
	return (1);
}

int	ft_remove_by_mod(char *nbr)
{
	if (ft_len(nbr) % 3 == 0)
	{
		if (!(ft_rm_chars(nbr, 3)))
			return (0);
	}
	else
	{
		if (!(ft_rm_chars(nbr, ft_len(nbr) % 3)))
			return (0);
	}
	return (1);
}

int	solve(char *nbr, t_str *dict, int nlines)
{
	char	temp[4];

	if (ft_len(nbr) > 3)
	{
		if (ft_len(nbr) % 3 == 0)
			ft_strlcpy(temp, nbr, 3);
		else if (ft_len(nbr) % 3 == 2)
			ft_strlcpy(temp, nbr, 2);
		else
			ft_strlcpy(temp, nbr, 1);
		ft_print_num(temp, dict, nlines);
		if (!(ft_len(temp) == 3 && (temp[0] == '0' && temp[1] == '0'
					&& temp[2] == '0')))
		{
			if (!(ft_print_position(nbr, dict, nlines, (ft_len(nbr) % 3))))
				return (0);
		}
		if (!(ft_remove_by_mod(nbr)))
			return (0);
		if (!(solve(nbr, dict, nlines)))
			return (0);
	}
	else
		ft_print_num(nbr, dict, nlines);
	return (1);
}
