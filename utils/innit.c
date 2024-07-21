/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:26:37 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/21 17:47:55 by mafourni         ###   ########.fr       */
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
	innit->a = NULL;
	innit->b = NULL;
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

void	ft_freeall(t_push_swap *all, int argc)
{
	int	i;
	i = 0;
	if (argc == 2)
	{
		if (all->split_result)
		{
			while (all->split_result[i] != NULL)
			{
				free(all->split_result[i]);
				i++;
			}
			free(all->split_result);
		}
	}
	if (argc > 2)
	{
		if (all->split_result)
		{
			free(all->split_result);
		}
	}
}
void free_linked_list(t_list *head_a, t_list *head_b) 
{
	t_list *tmp_a;
	t_list *tmp_b;

	while (head_a)
	{
		tmp_a = head_a;
		head_a = head_a->next;
		free(tmp_a);
	}
	while (head_b)
	{
		tmp_b = head_b;
		head_b = head_b->next;
		free(tmp_b);
	}
}

void free_norminette(t_push_swap *all, int argc)
{
	free_linked_list(all->a,all->b);
	ft_freeall(all,argc);
	free(all->atoi_result);
	free(all);
}