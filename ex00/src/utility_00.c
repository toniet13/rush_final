/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:17:26 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 18:18:41 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_n_of_lines(int file)
{
	char	temp[1];
	int		count;

	temp[0] = '0';
	count = 0;
	if (file == -1)
		return (-1);
	while (read(file, &temp[0], 1))
	{
		if (temp[0] == '\n')
			count++;
	}
	return (count);
}

int	ft_len(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret] != '\0')
	{
		ret++;
	}
	return (ret);
}
