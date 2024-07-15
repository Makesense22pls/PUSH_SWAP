/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:02:47 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/15 19:01:36 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	ft_sort(t_push_swap *all, int i)
{
	if (i == 2)
	{
		if ((int)all->A->content > (int)all->A->next->content)
			ft_swap_a(all);
	}
	if (i == 3)
		ft_sort3numbers(all);
	if (i == 4)
	{
		ft_findless4(all);
		ft_sort3numbers(all);
		ft_push_a(all);
	}
}



void	ft_findless4(t_push_swap *all)
{
	if ((int)all->A->content < (int)all->A->next->content && (int)all->A->content < (int)all->A->next->next->content && (int)all->A->content < (int)all->A->next->next->next->content)
		ft_push_b(all);
	if ((int)all->A->next->content < (int)all->A->content &&  (int)all->A->next->content < (int)all->A->next->next->content && (int)all->A->next->content < (int)all->A->next->next->next->content)
	{
		ft_swap_a(all);
		ft_push_b(all);
	}
	if ((int)all->A->next->next->content < (int)all->A->content && (int)all->A->next->next->content < (int)all->A->next->content && (int)all->A->next->content < (int)all->A->next->next->next->content)
	{
		ft_rotate_ra(all);
		ft_swap_a(all);
		ft_push_b(all);
	}
	if ((int)all->A->next->next->next->content < (int)all->A->content && (int)all->A->next->next->next->content < (int)all->A->next->content && (int)all->A->next->next->next->content< (int)all->A->next->next->content)
	{
		ft_rotate_rra(all);
		ft_push_b(all);
	}
}