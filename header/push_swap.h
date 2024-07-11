/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:41:49 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/11 19:22:06 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef	struct s_push_swap
{
	int 	check_parsing;
	int 	count_nb;
	char 	**split_result;
	long 	*atoi_result;
	int		index;
	int		nb_argc;
}			t_push_swap;

int		check_min_max(int argc, char **argv, t_push_swap *all);
bool	argcis2(int argc, char **argv);
bool	argcmore2(int argc, char **argv, t_push_swap *all);
t_push_swap	*ft_innit(void);
t_push_swap	*ft_mallocstruc(t_push_swap *innit);



//CHECK SIGN
int	ft_checkifgood(t_push_swap *all);
int		count_sign(char *str);
int		twoargtoatoi(char **str,t_push_swap *all);
int		moreargtoatoi(char **str,t_push_swap *all);
int		checksolosign(char *str);
// void	print(t_list *print);