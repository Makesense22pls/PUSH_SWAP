/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ck_wrong_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:59:49 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/13 17:49:58 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header/push_swap.h"

bool argcis2(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if ((argv[1][i] < '0' || argv[1][i] > '9') && argv[1][i] != ' ' && argv[1][i] != '-' && argv[1][i] != '+')
            {
                return (ft_printf("ERROR, char not allowed !\n"), false);
            }
            i++;
        }
        ft_printf("GO\n");
    }
	else
		return (false);
	return true;
}

bool	argcmore2(int argc, char **argv,t_push_swap *all)
{
	int i;
	int index;
	
	all->nb_argc = argc;
	index = 1;
	i = 0;
	if (argc > 2)
	{
		while (index < argc)
		{
			i = 0;
			while (argv[index][i] != '\0')
			{
				if ((argv[index][i] < '0' || argv[index][i] > '9') && argv[index][i] != '-' && argv[index][i] != '+')
				{	
					return (ft_printf("ERROR, char not allowed !\n"), false);
				}
				i++;	
			}
			index ++;
		}	
	}
	else
		return (false);
	return (true);
}