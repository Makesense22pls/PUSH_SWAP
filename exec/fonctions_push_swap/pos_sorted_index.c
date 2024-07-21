/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_sorted_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:02:47 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 20:20:04 by mafourni         ###   ########.fr       */
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
	if (pos == 0)
		ft_push_b(all);
	if (pos == 1)
	{
		ft_swap_a(all);
		ft_push_b(all);
	}
	if (pos == 2 || pos == 3)
		normpos2_3(all, pos);
}

void	normpos2_3(t_push_swap *all, int pos)
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
