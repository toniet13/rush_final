/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:19:04 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 18:19:12 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	iterator;

	iterator = 0;
	while (src[iterator] != '\0')
	{
		dest[iterator] = src[iterator];
		iterator++;
	}
	dest[iterator] = '\0';
	return (dest);
}

void	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	iterator;

	iterator = 0;
	while (src[iterator] != '\0' && iterator <= (size - 1))
	{
		dest[iterator] = src[iterator];
		iterator++;
	}
	dest[iterator] = '\0';
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, &*str, 1);
		str++;
	}
	write(1, " ", 1);
}
