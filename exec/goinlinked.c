/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goinlinked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:59:59 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 20:20:04 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	goinlinked(t_push_swap *all)
{
	int	h;
	int	i;
	int	check;

	h = 0;
	i = 0;
	check = 0;
	while (i < all->nb_numbers)
	{
		if (check++ == 0)
			all->a = ft_lstnew(all->atoi_result[i++]);
		ft_lstadd_back(&all->a, ft_lstnew(all->atoi_result[i]));
		i++;
	}
	h = ft_lstsize(all->a);
}
