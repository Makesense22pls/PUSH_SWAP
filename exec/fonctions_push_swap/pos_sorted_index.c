/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_sorted_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:02:47 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/21 18:34:48 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	ft_findmin(t_push_swap *all)
{
	int		pos;
	int		min;
	t_list	*current;

	current = all->a;
	pos = 0;
	min = (int)current->content;
	while (current->next != NULL)
	{
		if (min > (int)current->next->content)
			min = (int)current->next->content;
		current = current->next;
	}
	pos = ft_findpos(all->a, pos, min);
	printf("POS = [%d]\n", pos);
	if (pos == 0)
		ft_push_b(all);
	if (pos == 1)
	{
		ft_swap_a(all);
		ft_push_b(all);
	}
	if (pos == 2 || pos == 3 || pos == 4)
		normpos2_3_4(all, pos);
}

void	normpos2_3_4(t_push_swap *all, int pos)
{
	if (pos == 2)
	{
		ft_rotate_ra(all);
		ft_swap_a(all);
		ft_push_b(all);
	}
	if (pos == 3)
	{
		ft_rotate_rra(all);
		ft_push_b(all);
	}
	if (pos == 4)
	{
		ft_rotate_rra(all);
		ft_push_b(all);
	}
}

int	ft_findpos(t_list *A, int pos, int min)
{
	t_list	*tmp;

	pos = 0;
	tmp = A;
	while (min != (int)tmp->content)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	ft_index(t_push_swap *all)
{
	t_list	*save;

	all->list_size = ft_lstsize(all->a);
	all->max_value = ft_findmax(all);
	all->index = all->list_size -1;
	save = all->a;
	while (all->a != NULL)
	{
		if (all->max_value == (int)all->a->content && all->a->index == -1)
		{
			all->a->index = all->index;
			all->index --;
		}
		all->a = all->a->next;
	}
	all->a = save;
	all->index = all->list_size - 2;
	indexation(all, save);
	all->a = save;
	ft_sort(all, all->list_size);
}

void	indexation(t_push_swap *all, t_list *save)
{
	while (all->index != -1)
	{
		all->a = save;
		all->max_value = ft_givethemax(all);
		while (all->a != NULL)
		{
			if (all->max_value == (int)all->a->content)
			{
				all->a->index = all->index;
				all->index --;
			}
			all->a = all->a->next;
		}
	}
}
