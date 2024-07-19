/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:41:09 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/19 18:13:51 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	 main(int argc, char **argv)
{
	int wsh;
	// int tema = 0;
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
		all->list_size = ft_lstsize(all->A);
		ft_printf("LIST SIZE = [%d]", all->list_size);
		print(all->A);
		wsh = ft_findmax(all);
		ft_printf("MAX = [%d]", wsh);
		ft_index(all);
		// tema = is_list_sorted(all->A);
		ft_sort(all, all->list_size);
		ft_printf("\nAFTER SWAP :\n");
		ft_printf("A :\n");
		print(all->A);
		print(all->B);
		// while(all->A != NULL)
		// {
		// 	all->A->content = (int)all->A->content;
		// 	all->A = all->A->next;
		// }
		// tema = is_list_sorted(all->A);
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