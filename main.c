/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:41:09 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 20:20:04 by mafourni         ###   ########.fr       */
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
				return (ft_freeall(all), free(all), EXIT_FAILURE);
		}
		else
			if (argcmore2(argc, argv, all) == 0)
				return (ft_freeall(all), free(all), EXIT_FAILURE);
		if (check_min_max(argc, argv, all) == 1)
			return (ft_freeall(all), free(all), EXIT_FAILURE);
		goinlinked(all);
		all->list_size = ft_lstsize(all->a);
		ft_index(all);
		ft_sort(all, all->list_size);
		ft_freeall(all);
		free(all);
	}
	return (EXIT_SUCCESS);
}
