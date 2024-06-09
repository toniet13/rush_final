/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubal-c <mrubal-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:20:44 by mrubal-c          #+#    #+#             */
/*   Updated: 2024/06/09 21:56:41 by mrubal-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "dictionary.h"
#include "solver.h"
#include "utility.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		arg;
	int		file;
	int		nlines;
	char	*nbr;
	t_str	*dict;

	arg = ft_check_input(argc, argv);
	file = ft_check_file(argv, arg, &nlines);
	nbr = (char *)malloc(sizeof(char) * 50);
	if (arg == -1 || (file == -1) || nbr == NULL)
		return (1);
	dict = (struct str *)malloc(sizeof(*dict) * nlines);
	if (dict == NULL)
		return (1);
	if (!(mem_alloc(dict, nlines)))
		return (1);
	dict_init(dict, file, nlines);
	close(file);
	if (ft_strcpy(nbr, ft_rm_zero(argv[arg])) == NULL)
		return (1);
	if (!(solve(nbr, dict, nlines)))
		return (1);
	ft_free_all(dict, nlines, nbr);
	return (0);
}
