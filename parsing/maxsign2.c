/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxsign2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:05:26 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/20 20:20:04 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	checksolosign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (1);
		}
		i++;
	}
	return (0);
}

int	doublon(t_push_swap *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->nb_numbers - 1)
	{
		j = i + 1;
		while (j < all->nb_numbers)
		{
			if (all->atoi_result[i] == all->atoi_result[j])
			{
				ft_printf(" I = [%d]\n", all->atoi_result[i]);
				ft_printf(" J =[%d]\n", all->atoi_result[j]);
				ft_printf("DOUBLON FOUND\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	print(t_list *print)
{
	t_list	*tmp;

	if (print)
	{
		tmp = print;
		while (tmp != NULL)
		{
			printf("[%d]\n", (int)tmp->content);
			tmp = tmp->next;
		}
		printf("END\n");
	}
	else
		printf("ERROR IN PRINTING LIST EMPTY");
}

void	check(t_list *print)
{
	t_list	*tmp;

	if (print)
	{
		tmp = print;
		while (tmp != NULL)
		{
			printf("[%d]\n", (int)tmp->content);
			tmp = tmp->next;
		}
	}
	else
		printf("ERROR IN PRINTING LIST EMPTY");
}
