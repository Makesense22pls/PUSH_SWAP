/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goinlinked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:59:59 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/13 17:48:55 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header/push_swap.h"

void	goinlinked(t_push_swap *all)
{
	int h = 0;
	int i = 0;
	int check = 0;
	
	while (i < all->nb_numbers)
	{
		if (check++ == 0)
			all->A = ft_lstnew((void *)all->atoi_result[i++]);
		ft_lstadd_back(&all->A,ft_lstnew((void *)all->atoi_result[i]));
		i++;
	}
	h = ft_lstsize(all->A);
	printf("TAILLE DE LA LISTE : ---[%d]---\n", h);
	print(all->A);
}