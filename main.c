/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:41:09 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 17:12:39 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	 main(int argc, char **argv)
{
	t_push_swap *all;
	if (argc >= 2)
	{
		all = ft_innit();
		if (argc == 2)
		{
			if (argcis2(argc, argv) == 0)
			{
				ft_freeall(all);
				free(all);	
				return (EXIT_FAILURE);
			}
		}
		else
			if (argcmore2(argc, argv, all) == 0)
			{
				ft_freeall(all);
				free(all);	
				return (EXIT_FAILURE);
			}
		if (check_min_max(argc, argv,all) == 1)
		{
			ft_freeall(all);
			free(all);	
			return (EXIT_FAILURE);
		}
		goinlinked(all);
		all->list_size = ft_lstsize(all->A);
		ft_index(all);
		ft_sort(all, all->list_size);
		ft_freeall(all);
		free(all);
	}
	return (EXIT_SUCCESS);
}

















// int	 main(int argc, char **argv)
// {

// 	t_push_swap *all;
// 	int i;
// 	i = 1;
// 	// t_list *A;
// 	all = ft_innit();
// 	if (argcis2(argc, argv) == 0)
// 		return (EXIT_FAILURE);
// 	if (argcmore2(argc, argv) == 0)
// 		return (EXIT_FAILURE);
// 	check_min_max(argc, argv, all);
// 	// A = ft_lstnew(ft_atoi(argv[i]));
// 	// while (argc != 1)
// 	// {
// 	// 	ft_lstadd_back(&A,ft_lstnew(argv[++i]));
// 	// 	argc --;
// 	// }
// 	return (EXIT_SUCCESS);
// }