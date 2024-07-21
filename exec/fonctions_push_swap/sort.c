/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:49:34 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 20:20:19 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	ft_sort(t_push_swap *all, int i)
{
	if (i == 2)
	{
		if ((int)all->a->content > (int)all->a->next->content)
			ft_swap_a(all);
	}
	if (i == 3)
		ft_sort3numbers(all);
	if (i == 4)
	{
		ft_findmin(all);
		ft_sort3numbers(all);
		ft_push_a(all);
	}
	if (i == 5)
	{
		ft_findmin(all);
		ft_findmin(all);
		ft_sort3numbers(all);
		if (all->b->content < all->b->next->content)
			ft_swap_b(all);
		ft_push_a(all);
		ft_push_a(all);
	}
	if (i >= 6)
		goradix(all);
}

bool	is_list_sorted(t_list *head)
{
	t_list	*current;

	current = head;
	if (head == NULL || head->next == NULL)
		return (true);
	while (current->next != NULL)
	{
		if ((int)current->content > (int)current->next->content)
			return (false);
		current = current->next;
	}
	return (true);
}

void	ft_push_ss(t_push_swap *all)
{
	ft_swap_a(all);
	ft_swap_b(all);
	ft_printf("ss\n");
}
