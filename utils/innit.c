/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:26:37 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 17:57:23 by mafourni         ###   ########.fr       */
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
	innit->count_call = 0;
	innit->list_size = 0;
	innit->max_value = 0;

	return (innit);
}
t_push_swap	*ft_mallocstruc(t_push_swap *innit)
{
	innit = malloc(sizeof(t_push_swap));
	if (!innit)
		return (0);
	return (innit);
}

void	ft_freeall(t_push_swap *all)
{
	// int long j = 0;
	int i = 0;
	if (all->split_result)
	{
		while (all->split_result[i])
		{
			free(all->split_result[i]);
			i++;
		}
		free(all->split_result);
	}
	if (all->atoi_result != NULL)
		free(all->atoi_result);
	if (all->A)
	{
		t_list *tmp;
		tmp = NULL;
		while(all->A != NULL)
		{
			all->A = tmp;
			free(all->A);
			all->A =tmp->next;
		}
		free(all->A);
	}
	if (all->B)
	{
		t_list *tmp;
		tmp = NULL;
		while(all->B != NULL)
		{
			all->A = tmp;
			free(all->B);
			all->B = tmp->next;
		}
		free(all->B);
	}
}
