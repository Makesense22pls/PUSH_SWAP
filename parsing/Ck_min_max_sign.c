/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ck_min_max_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:57:01 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/21 17:25:20 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	check_min_max(int argc, char **argv, t_push_swap *all)
{
	if (argc == 2)
	{
		if (twoargtoatoi(argv, all) == 1)
			return (1);
	}
	else
	{
		if (moreargtoatoi(argv, all) == 1)
			return (1);
	}
	if (doublon(all) == 1)
		return (1);
	return (0);
}

int	ft_checkifgood(t_push_swap *all, int reset)
{
	int	i;

	i = 0;
	while (all->split_result[i] != NULL)
	{
		if (checksolosign(all->split_result[i]) == 1)
			return (ft_printf("ERROR, SIGNE ALONE\n"), 1);
		if (count_sign(all->split_result[i]) > 1)
		{
			printf("ERROR,PLUS DE 1 signe \n");
			return (1);
		}
		if (count_sign(all->split_result[i]) == 1 && \
			(all->split_result[i][0] != '+') \
			&& (all->split_result[i][0] != '-'))
		{
			printf("ERROR, SIGNE MAUVAISE PLACE \n");
			return (1);
		}
		i++;
	}
	reset = 0;
	return (0);
}

int	count_sign(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			count ++;
		i++;
	}
	return (count);
}

int	twoargtoatoi(char **str, t_push_swap *all)
{
	int	i;

	i = 0;
	all->split_result = ft_split(str[1], 32);
	if (ft_checkifgood(all, i) == 1)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	while (all->split_result[i] != NULL)
		i++;
	all->nb_numbers = i;
	all->atoi_result = malloc(sizeof(long int *) * (i));
	i = 0;
	while (all->split_result[i] != NULL)
	{
		all->atoi_result[i] = (long int)ft_atoi(all->split_result[i]);
		if (all->atoi_result[i] <= -2147483648)
			return (printf("ERROR, LOWER INT_MIN\n"), 1);
		if (all->atoi_result[i] >= 2147483647)
			return (printf("ERROR, UPPER INT MAX\n"), 1);
		i++;
	}
	return (0);
}

int	moreargtoatoi(char **str, t_push_swap *all)
{
	int	i;

	i = 0;
	all->split_result = malloc(sizeof(char *) * (all->nb_argc));
	while (i + 1 < all->nb_argc)
	{
		all->split_result[i] = str[i + 1];
		i++;
	}
	all->split_result[i] = NULL;
	if (ft_checkifgood(all, i) == 1)
		return (ft_printf("ERROR\n"), 1);
	ft_go(all, i);
	all->nb_numbers = i;
	all->atoi_result = malloc(sizeof(long int *) * (i));
	i = 0;
	while (all->split_result[i] != NULL)
	{
		all->atoi_result[i] = (long int)ft_atoi(all->split_result[i]);
		if (all->atoi_result[i] < -2147483648 || \
			all->atoi_result[i] > 2147483647)
			return (printf("ERROR, LOWER INT_MIN OR UPPER INT_MAX"), 1);
		i++;
	}
	return (0);
}
