/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapthingsp2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:56:54 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 20:20:19 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	ft_rotate_rb(t_push_swap *all)
{
	void	*tmp_headnext;
	t_list	*tmp;

	tmp_headnext = all->b->next;
	tmp = all->b;
	ft_lstadd_back(&all->b, all->b);
	all->b = tmp_headnext;
	ft_printf("rb\n");
}

void	ft_rotate_rr(t_push_swap *all)
{
	ft_rotate_ra(all);
	ft_rotate_rb(all);
	ft_printf("rr\n");
}

void	ft_rotate_rra(t_push_swap *all)
{
	void	*tmp_tail;
	t_list	*prev;
	t_list	*tmp;

	tmp = all->a;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp_tail = tmp;
	ft_lstadd_front(&all->a, tmp_tail);
	if (prev)
		prev->next = NULL;
	ft_printf("rra\n");
}

void	ft_rotate_rrb(t_push_swap *all)
{
	void	*tmp_tail;
	t_list	*tmp;
	t_list	*prev;

	tmp = all->b;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp_tail = tmp;
	ft_lstadd_front(&all->b, tmp_tail);
	if (prev)
		prev->next = NULL;
	ft_printf("rb\n");
}

void	ft_rotate_rrr(t_push_swap *all)
{
	ft_rotate_rra(all);
	ft_rotate_rrb(all);
	ft_printf("rrr\n");
}
