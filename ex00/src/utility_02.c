/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:19:25 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 21:59:25 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include <stdlib.h>

int	ft_rm_chars(char *nbr, int n)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_len(nbr)));
	if (ret == NULL)
		return (0);
	i = 0;
	while (nbr[i + n])
	{
		ret[i] = nbr[i + n];
		i++;
	}
	ret[i] = '\0';
	ft_strcpy(nbr, ret);
	return (1);
}

char	*ft_rm_zero(char *nbr)
{
	while (*nbr == '0' && ft_len(nbr) > 1)
		if (!(ft_rm_chars(nbr, 1)))
			return (NULL);
	return (nbr);
}

void	ft_free_all(struct str *dict, int nlines, char *nbr)
{
	int	i;

	i = 0;
	while (i < nlines)
	{
		free(dict[i].word);
		free(dict[i].nbr);
		i++;
	}
	free(dict);
	free(nbr);
}
