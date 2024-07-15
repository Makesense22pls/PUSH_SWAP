/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3nombres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:12:12 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/15 17:49:59 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"header/push_swap.h"

void	ft_sort3numbers(t_push_swap *all)
{
	if ((int)all->A->content > (int)all->A->next->content && (int)all->A->next->content < (int)all->A->next->next->content && (int)all->A->next->next->content < (int)all->A->content)
		ft_rotate_ra(all);
	if ((int)all->A->content > (int)all->A->next->content && (int)all->A->next->content < (int)all->A->next->next->content && (int)all->A->next->next->content > (int)all->A->content)
		ft_swap_a(all);
	if ((int)all->A->content > (int)all->A->next->content && (int)all->A->next->content > (int)all->A->next->next->content)
	{
		ft_swap_a(all);
		ft_rotate_rra(all);
	}
	if ((int)all->A->content < (int)all->A->next->content && (int)all->A->next->content < (int)all->A->next->next->content)
		return;

	if ((int)all->A->content < (int)all->A->next->content && (int)all->A->next->content > (int)all->A->next->next->content)
	{
		ft_swap_a(all);
		ft_rotate_ra(all);
	}
	if ((int)all->A->content > (int)all->A->next->content)
		ft_swap_a(all);
}		