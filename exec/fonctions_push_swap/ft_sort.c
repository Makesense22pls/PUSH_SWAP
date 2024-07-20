/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:02:47 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 17:09:40 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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
		ft_findmin(all);
		ft_sort3numbers(all);
		ft_push_a(all);
	}
	if (i == 5)
	{
		ft_findmin(all);
		ft_findmin(all);
		ft_sort3numbers(all);
		if (all->B->content < all->B->next->content)
			ft_swap_b(all);
		ft_push_a(all);
		ft_push_a(all);
	}
	if (i >= 6)
	{
		goradix(all);
	}	
}



void	ft_findmin(t_push_swap *all)
{
	int pos = 0;
	t_list *current = all->A;
	int min = (int)current->content;
	while (current->next != NULL)
	{
		// ft_printf(" MIN = [%d]\n", min);
		// ft_printf("(int)current->next->content = [%d]\n",(int)current->next->content);
		if (min > (int)current->next->content)
				min = (int)current->next->content;
		current = current->next;
	}
	// printf(" MIN FINALE = [%d]\n", min);
	pos = ft_findpos(all->A, pos, min);
	// printf(" POS = [%d]\n", pos);
	if (pos == 0)
		ft_push_b(all);
	if (pos == 1)
	{
		ft_swap_a(all);
		ft_push_b(all);
	}
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
int ft_findpos(t_list *A, int pos, int min)
{
	pos = 0;
	t_list *tmp = A;
	while(min != (int)tmp->content)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}
bool is_list_sorted(t_list *head)
{ 
	if (head == NULL || head->next == NULL) 
		return true;
	t_list *current = head;
	while (current->next != NULL) 
	{ 
		// ft_printf("oe\n");
		if ((int)current->content > (int)current->next->content) 
			return (false);
		current = current->next;
	}
	return (true);
}


void	ft_index(t_push_swap *all)
{
	all->max_value = ft_findmax(all);
	all->index = all->list_size -1;
	t_list *save = all->A;
	while (all->A != NULL)
	{
		if (all->max_value == (int)all->A->content && all->A->index == -1)
		{
			// ft_printf("IN\n");
			all->A->index = all->index;
			all->index --;
		}
		all->A = all->A->next;
	}
	all->A = save;
	all->index = all->list_size - 2;
	while(all->index != -1)
	{	
		all->A = save;
		all->max_value = ft_givethemax(all);
		while (all->A != NULL)
		{
			if (all->max_value == (int)all->A->content)
			{
				all->A->index = all->index;
				all->index --;
			}
			all->A = all->A->next;
		}
	}
	// all->A = save;
	// while(all->A != NULL)
	// {
	// 	// printf("I-[%d]-I\n", all->A->index);
	// 	all->A = all->A->next;
	// }
	all->A = save;
}

int ft_givethemax(t_push_swap *all)
{
    int nextmax = INT_MIN;
    t_list *current = all->A;

    while (current != NULL)
    {
        if (current->index == -1 && (int)current->content > nextmax && (int)current->content < all->max_value)
            nextmax = (int)current->content;
        current = current->next;
    }
    if (nextmax == INT_MIN)
        return (all->max_value);
    all->max_value = nextmax;
    return (nextmax);
}
int	ft_findmax(t_push_swap *all)
{
	t_list *save = all->A;
	int max = (int)all->A->content;
	while (all->A->next != NULL)
	{
		if (max < (int)all->A->next->content)
				max = (int)all->A->next->content;
		all->A = all->A->next;
	}
	all->A = save;
	return (max);
}

static int	ft_max_bits(t_list **list)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *list;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
void	goradix(t_push_swap *all)
{
	t_list *first_elem_A;
	int i;
	int j;
	int max_bits;
	
	i = 0;
	first_elem_A = all->A;
	max_bits = ft_max_bits(&(all->A));
	while (i < max_bits)
	{
		j = 0;
		while (j++ < all->list_size)
		{
			first_elem_A = all->A;
			if (((first_elem_A->index >> i) & 1) == 1)
				ft_rotate_ra(all);
			else
				ft_push_b(all);
		}
		while (ft_lstsize(all->B) != 0)
			ft_push_a(all);
		i++;
	}
}
