# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 12:27:52 by kmaeda            #+#    #+#              #
#    Updated: 2025/07/15 12:43:03 by kmaeda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -ILibft

LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = push_swap.c quick_sort.c core_ops.c push_swap_ops.c rotate_ops.c \
	rev_rotate_ops.c sort_small.c chunk_sorting.c chunk_utils.c create_stack.c \
	chunk_greedy.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_LIB) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

