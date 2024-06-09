/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:06:57 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 21:58:15 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "utility.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_get_wrd(char *nbr, t_str *dict, int nlines)
{
	int	i;

	i = 0;
	while (i < nlines)
	{
		if (ft_strcmp(dict[i].nbr, nbr) == 0)
			return (dict[i].word);
		i++;
	}
	return ("Dict Error\n");
}

int	mem_alloc(t_str *dict, int nlines)
{
	int	i;

	i = 0;
	while (i < nlines)
	{
		dict[i].nbr = (char *)malloc(sizeof(char) * 50);
		if (dict[i].nbr == NULL)
			return (0);
		dict[i].word = (char *)malloc(sizeof(char) * 100);
		if (dict[i].word == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	read_nbr(t_str *dict, int file, char *temp, int i)
{
	int	j;

	j = 0;
	read(file, &temp[0], 1);
	while (!ft_is_num(temp[0]))
		read(file, &temp[0], 1);
	while (ft_is_num(temp[0]))
	{
		dict[i].nbr[j++] = temp[0];
		read(file, &temp[0], 1);
	}
}

void	read_wrd(t_str *dict, int file, char *temp, int i)
{
	int	j;

	j = 0;
	while (temp[0] == ' ')
		read(file, &temp[0], 1);
	while (temp[0] != '\n')
	{
		dict[i].word[j++] = temp[0];
		read(file, &temp[0], 1);
	}
}

void	dict_init(t_str *dict, int file, int nlines)
{
	int		i;
	int		j;
	char	temp[1];

	j = 0;
	i = 0;
	while (i < nlines)
	{
		read_nbr(dict, file, temp, i);
		while (temp[0] != ':')
			read(file, &temp[0], 1);
		read(file, &temp[0], 1);
		read_wrd(dict, file, temp, i);
		ft_strcpy(dict[i].nbr, ft_rm_zero(dict[i].nbr));
		i++;
	}
}
