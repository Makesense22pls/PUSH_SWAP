/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:38:54 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/15 19:30:28 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	ft_swap_a(t_push_swap *all)
{
	void *tmp_content;
	
	tmp_content = all->A->content;
	if(all->A == NULL || all->A->content == NULL || all->A->next == NULL)
		return;
	all->A->content = all->A->next->content;
	all->A->next->content = tmp_content;
	ft_printf("-[%d]-[sa]\n",++all->count_call);
}

void	ft_swap_b(t_push_swap *all)
{
	void *tmp_content;
	
	tmp_content = all->B->content;
	if(all->B == NULL || all->B->content == NULL || all->B->next == NULL)
		return;
	all->B->content = all->B->next->content;
	all->B->next->content = tmp_content;
	ft_printf("-[%d]-[sb]\n"), ++all->count_call;
}

void	ft_push_ss(t_push_swap *all)
{
	ft_swap_a(all);
	ft_swap_b(all);
	ft_printf("-[%d]-[ss]\n"), ++all->count_call;
}

void	ft_push_a(t_push_swap *all)
{
	t_list *tmp;

    if (NULL == all->B)
        return;
    tmp = all->B;
    all->B = (all->B)->next;
    tmp->next = all->A;
    all->A = tmp;
	// ft_lstadd_front(&all->A, all->B);
	ft_printf("-[%d]-[pa]\n"), ++all->count_call;
}

void	ft_push_b(t_push_swap *all)
{
	// ft_lstadd_front(&all->A, all->B);
	t_list *tmp;

    if (NULL == all->A)
        return;
    tmp = all->A;
    all->A = (all->A)->next;
    tmp->next = all->B;
    all->B = tmp;
	ft_printf("-[%d]-[pb]\n"), ++all->count_call;
}


void	ft_rotate_ra(t_push_swap *all)
{
	void	*tmp_headnext;

	tmp_headnext = all->A->next;
	
	t_list *tmp;

	tmp = all->A;
	ft_lstadd_back(&all->A,all->A);
	
	all->A = tmp_headnext;
	ft_printf("-[%d]-[ra]\n"), ++all->count_call;
}

void	ft_rotate_rb(t_push_swap *all)
{
	void	*tmp_headnext;

	tmp_headnext = all->B->next;
	
	t_list *tmp;

	tmp = all->B;
	ft_lstadd_back(&all->B,all->B);
	
	all->B = tmp_headnext;
	ft_printf("-[%d]-[rb]\n"), ++all->count_call;
}

void	ft_rotate_rr(t_push_swap *all)
{
	ft_rotate_ra(all);
	ft_rotate_rb(all);
	ft_printf("-[%d]-[rr]\n"), ++all->count_call;
}

void ft_rotate_rra(t_push_swap *all)
{
	void	*tmp_tail;
	
	t_list 	*prev;
	t_list *tmp;

	tmp = all->A;

	while(tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	// ft_printf("---[%d]---", tmp->content);
	tmp_tail = tmp;
	ft_lstadd_front(&all->A,tmp_tail);
	if (prev)
		prev->next = NULL;
	ft_printf("-[%d]-[rra]\n", ++all->count_call);
}

void ft_rotate_rrb(t_push_swap *all)
{
	void	*tmp_tail;
	
	t_list 	*prev;
	t_list *tmp;

	tmp = all->B;

	while(tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	ft_printf("---[%d]---", tmp->content);
	tmp_tail = tmp;
	ft_lstadd_front(&all->B,tmp_tail);
	if (prev)
		prev->next = NULL;
	ft_printf("-[%d]-[rrb]\n", ++all->count_call);
}

void 	ft_rotate_rrr(t_push_swap *all)
{
	ft_rotate_rra(all);
	ft_rotate_rrb(all);
	ft_printf("-[%d]-[rrr]\n", ++all->count_call);
}