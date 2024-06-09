/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:13:05 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 21:56:31 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "utility.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_check_nbr(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] != '\0')
	{
		if (!(ft_is_num(nbr[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_file(char *argv[], int arg, int *nlines)
{
	int	file;
	int	count;

	count = 0;
	if (arg == 1)
		file = open("numbers.dict", O_RDONLY);
	else
		file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	*nlines = ft_n_of_lines(file);
	close(file);
	if (arg == 1)
		file = open("numbers.dict", O_RDONLY);
	else
		file = open(argv[1], O_RDONLY);
	return (file);
}

int	ft_check_input(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (!(ft_check_nbr(argv[1])) || argv[1][0] == '\0')
			write(1, "Error\n", 6);
		else
			return (1);
	}
	else if (argc == 3)
	{
		if (!(ft_check_nbr(argv[2])) || argv[2][0] == '\0')
			write(1, "Error\n", 6);
		else
			return (2);
	}
	else
		write(1, "Error\n", 6);
	return (-1);
}
