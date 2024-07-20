/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:41:09 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/19 20:03:25 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	ft_freeall(t_push_swap *all)
{
	int i = 0;
	if (all->split_result)
	{
		while (all->split_result[i])
		{
			free(all->split_result[i]);
			i++;
		}
	}
	free(all->split_result);
}
int	 main(int argc, char **argv)
{
	int wsh;
	// int tema = 0;
	t_push_swap *all;
	all = NULL;
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
		// ft_printf("LIST SIZE = [%d]", all->list_size);
		// print(all->A);
		wsh = ft_findmax(all);
		// ft_printf("MAX = [%d]", wsh);
		ft_index(all);
		// tema = is_list_sorted(all->A);
		ft_sort(all, all->list_size);
		ft_freeall(all);
		free(all);
		// ft_printf("\nAFTER SWAP :\n");
		// ft_printf("A :\n");
		// print(all->A);
		// print(all->B);
		// while(all->A != NULL)
		// {
		// 	all->A->content = (int)all->A->content;
		// 	all->A = all->A->next;
		// }
		// tema = is_list_sorted(all->A);
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