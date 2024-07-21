/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapthingsp1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:38:54 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 20:20:19 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	ft_swap_a(t_push_swap *all)
{
	int	tmp_content;

	tmp_content = all->a->content;
	if (all->a == NULL || all->a->next == NULL)
		return ;
	all->a->content = all->a->next->content;
	all->a->next->content = tmp_content;
	ft_printf("sa\n");
}

void	ft_swap_b(t_push_swap *all)
{
	int	tmp_content;

	tmp_content = all->b->content;
	if (all->b == NULL || all->b->next == NULL)
		return ;
	all->b->content = all->b->next->content;
	all->b->next->content = tmp_content;
	ft_printf("sb\n");
}

void	ft_push_a(t_push_swap *all)
{
	t_list	*tmp;

	if (NULL == all->b)
		return ;
	tmp = all->b;
	all->b = (all->b)->next;
	tmp->next = all->a;
	all->a = tmp;
	ft_printf("pa\n");
}

void	ft_push_b(t_push_swap *all)
{
	t_list	*tmp;

	if (NULL == all->a)
		return ;
	tmp = all->a;
	all->a = (all->a)->next;
	tmp->next = all->b;
	all->b = tmp;
	ft_printf("pb\n");
}

void	ft_rotate_ra(t_push_swap *all)
{
	t_list	*tmp;
	void	*tmp_headnext;

	tmp_headnext = all->a->next;
	tmp = all->a;
	ft_lstadd_back(&all->a, all->a);
	all->a = tmp_headnext;
	ft_printf("ra\n");
}
