/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3nombres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:12:12 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/21 18:24:37 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	ft_sort3numbers(t_push_swap *all)
{
	if ((int)all->a->content > (int)all->a->next->content && \
		(int)all->a->next->content < (int)all->a->next->next->content && \
		(int)all->a->next->next->content < (int)all->a->content)
		ft_rotate_ra(all);
	if ((int)all->a->content > (int)all->a->next->content && \
		(int)all->a->next->content < (int)all->a->next->next->content && \
		(int)all->a->next->next->content > (int)all->a->content)
		ft_swap_a(all);
	if ((int)all->a->content > (int)all->a->next->content && \
		(int)all->a->next->content > (int)all->a->next->next->content)
	{
		ft_swap_a(all);
		ft_rotate_rra(all);
	}
	if ((int)all->a->content < (int)all->a->next->content && \
		(int)all->a->next->content < (int)all->a->next->next->content)
		return ;
	if ((int)all->a->content < (int)all->a->next->content && \
		(int)all->a->next->content > (int)all->a->next->next->content)
	{
		ft_swap_a(all);
		ft_rotate_ra(all);
	}
	if ((int)all->a->content > (int)all->a->next->content)
		ft_swap_a(all);
}

int	ft_findmax(t_push_swap *all)
{
	t_list	*save;
	int		max;

	save = all->a;
	max = (int)all->a->content;
	while (all->a->next != NULL)
	{
		if (max < (int)all->a->next->content)
			max = (int)all->a->next->content;
		all->a = all->a->next;
	}
	all->a = save;
	return (max);
}

static int	ft_max_bits(t_list **list)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *list;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	goradix(t_push_swap *all)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		max_bits;

	i = 0;
	head_a = all->a;
	max_bits = ft_max_bits(&(all->a));
	while (i < max_bits)
	{
		j = 0;
		while (j++ < all->list_size)
		{
			head_a = all->a;
			if (((head_a->index >> i) & 1) == 1)
				ft_rotate_ra(all);
			else
				ft_push_b(all);
		}
		while (ft_lstsize(all->b) != 0)
			ft_push_a(all);
		i++;
	}
}

int	ft_givethemax(t_push_swap *all)
{
	int		nextmax;
	t_list	*current;

	nextmax = INT_MIN;
	current = all->a;
	while (current != NULL)
	{
		if (current->index == -1 && (int)current->content > nextmax && \
			(int)current->content < all->max_value)
			nextmax = (int)current->content;
		current = current->next;
	}
	if (nextmax == INT_MIN)
		return (all->max_value);
	all->max_value = nextmax;
	return (nextmax);
}
