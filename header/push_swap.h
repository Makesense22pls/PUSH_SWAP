/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:41:49 by mafourni          #+#    #+#             */
/*   Updated: 2024/07/19 18:02:20 by mafourni         ###   ########.fr       */
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
	int		nb_numbers;
	t_list 	*A;
	t_list 	*B;
	int 	list_size;
	int		count_call;
	int max_value;
}			t_push_swap;

int		check_min_max(int argc, char **argv, t_push_swap *all);
bool	argcis2(int argc, char **argv);
bool	argcmore2(int argc, char **argv, t_push_swap *all);
t_push_swap	*ft_innit(void);
t_push_swap	*ft_mallocstruc(t_push_swap *innit);

// PUSH SWAP FUNCTIONS
void	ft_swap_a(t_push_swap *all);
void	ft_swap_b(t_push_swap *all);
void	ft_push_ss(t_push_swap *all);
void	ft_push_a(t_push_swap *all);
void	ft_push_b(t_push_swap *all);
void	ft_rotate_ra(t_push_swap *all);
void	ft_rotate_rb(t_push_swap *all);
void	ft_rotate_rra(t_push_swap *all);
void 	ft_rotate_rrb(t_push_swap *all);
void 	ft_rotate_rrr(t_push_swap *all);

// SORT NUMBERS

void	ft_sort3numbers(t_push_swap *all);
bool 	is_list_sorted(t_list *head);
void	ft_findmin(t_push_swap *all);
int 	ft_findpos(t_list *A, int pos, int min);
void	ft_index(t_push_swap *all);
int	ft_findmax(t_push_swap *all);
int		ft_givethemax(t_push_swap *all);
//CHECK SIGN
int		ft_checkifgood(t_push_swap *all);
int		count_sign(char *str);
int		twoargtoatoi(char **str,t_push_swap *all);
int		moreargtoatoi(char **str,t_push_swap *all);
int		checksolosign(char *str);
int		doublon(t_push_swap *all);
void	goinlinked(t_push_swap *all);
void	print(t_list *print);


// RADIX
void		goradix(t_push_swap *all);
// static int	ft_max_bits(t_list **list);

void	ft_sort(t_push_swap *all, int i);