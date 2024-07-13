/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:38:54 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/13 18:55:49 by mafourni         ###   ########.fr       */
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
	ft_printf("[sa]");
}

void	ft_swap_b(t_push_swap *all)
{
	void *tmp_content;
	
	tmp_content = all->B->content;
	if(all->B == NULL || all->B->content == NULL || all->B->next == NULL)
		return;
	all->B->content = all->B->next->content;
	all->B->next->content = tmp_content;
	ft_printf("[sb]");
}

void	ft_push_ss(t_push_swap *all)
{
	ft_swap_a(all);
	ft_swap_b(all);
	ft_printf("[ss]");
}

void	ft_push_a(t_push_swap *all)
{
	ft_lstadd_front(&all->A, all->B);
}

void	ft_push_b(t_push_swap *all)
{
	ft_lstadd_front(&all->B, all->A);
}