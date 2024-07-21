/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:41:09 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/21 17:49:50 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*all;

	if (argc >= 2)
	{
		all = ft_innit();
		if (argc == 2)
		{
			if (argcis2(argc, argv) == 0)
				return (ft_freeall(all, argc), free(all), EXIT_FAILURE);
		}
		else
			if (argcmore2(argc, argv, all) == 0)
				return (ft_freeall(all, argc), free(all), EXIT_FAILURE);
		if (check_min_max(argc, argv, all) == 1)
			return (ft_freeall(all, argc), free(all), EXIT_FAILURE);
		goinlinked(all);
		if (is_list_sorted(all->a) == 1)
			return (free_norminette(all, argc), EXIT_SUCCESS);
		ft_index(all);
		free_norminette(all, argc);
	}
	return (EXIT_SUCCESS);
}
