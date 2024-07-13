/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:26:37 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/12 19:17:37 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

t_push_swap	*ft_innit(void)
{
	t_push_swap	*innit;

	innit = NULL;
	innit = ft_mallocstruc(innit);
	innit->split_result = NULL;
	innit->atoi_result = NULL;
	innit->count_nb = 0;
	innit->nb_argc = 0;
	innit->nb_numbers = 0;
	innit->A = NULL;
	innit->B = NULL;

	return (innit);
}
t_push_swap	*ft_mallocstruc(t_push_swap *innit)
{
	innit = malloc(sizeof(t_push_swap));
	if (!innit)
		return (0);
	return (innit);
}