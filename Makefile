# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:01:19 by mafourni          #+#    #+#              #
#    Updated: 2024/07/21 18:39:19 by mafourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g 
RM = rm -f

# SRC
SRC = parsing/Ck_min_max_sign.c parsing/Ck_wrong_char.c main.c utils/innit.c exec/goinlinked.c parsing/maxsign2.c\
		exec/fonctions_push_swap/swapthingsp2.c exec/fonctions_push_swap/swapthingsp1.c exec/fonctions_push_swap/ft_3nombres.c exec/fonctions_push_swap/sort.c exec/fonctions_push_swap/pos_sorted_index.c
OBJ = $(SRC:.c=.o)


# LIB
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# HEADERS
HEADERS_LIB = $(LIBFT_DIR)

all : $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

%.o: %.c
	gcc $(CFLAGS) -I. -I$(HEADERS_LIB) -c $< -o $@ 

$(NAME): $(OBJ)
	 	gcc  $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)


clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean 

re: fclean all