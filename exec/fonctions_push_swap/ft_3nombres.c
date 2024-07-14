/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3nombres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:12:12 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/14 18:58:16 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"header/push_swap.h"

void	ft_sort3numbers(t_push_swap *all)
{	
	if (all->A->content > all->A->next->content && all->A->next->content < all->A->next->next->content && all->A->next->next->content < all->A->content)
		ft_rotate_ra(all);
	if (all->A->content > all->A->next->content && all->A->next->content < all->A->next->next->content && all->A->next->next->content > all->A->content)
		ft_swap_a(all);
	if (all->A->content > all->A->next->content && all->A->next->content > all->A->next->next->content)
	{
		ft_swap_a(all);
		ft_rotate_rra(all);
	}
	if (all->A->content < all->A->next->content && all->A->next->content < all->A->next->next->content)
		return;
	if (all->A->content < all->A->next->content && all->A->next->content > all->A->next->next->content)
	{
		ft_swap_a(all);
		ft_rotate_ra(all);
	}

}		