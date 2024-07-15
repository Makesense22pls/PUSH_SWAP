/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:41:09 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/15 19:27:08 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	 main(int argc, char **argv)
{
	int i = 0;
	t_push_swap *all;
	if (argc >= 2)
	{
		all = ft_innit();
		if (argc == 2)
		{
			if (argcis2(argc, argv) == 0)
				return (EXIT_FAILURE);
		}
		else
			if (argcmore2(argc, argv, all) == 0)
				return (EXIT_FAILURE);
		if (check_min_max(argc, argv,all) == 1)
			return (EXIT_FAILURE);
		goinlinked(all);
		i = ft_lstsize(all->A);
		print(all->A);
		ft_push_b(all);
		// ft_sort(all, i);
		ft_printf("\nAFTER SWAP :\n");
		i = ft_lstsize(all->B);
		ft_printf("eee[%d]ee", i);
		print(all->A);
		print(all->B);
	}
	return (EXIT_SUCCESS);
}

// void	print(t_list *print)
// {
// 	int node = 0;
// 	t_list *tmp;

// 	if (print)
// 	{
// 		tmp = print;
// 		while (tmp != NULL)
// 		{
// 			printf("%s",tmp->content);
// 			tmp = tmp->next;
// 		}
// 	}
// 	else
// 		printf("ERROR IN PRINTING LIST EMPTY");
// }




// int main()
// {
// 	long int i = atoi("2147483650");
// 	printf("[%ld]\n", i);
// }
















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