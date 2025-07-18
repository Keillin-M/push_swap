/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:55:22 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/11 14:13:14 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_data
{
	int	size;
	int	target;
	int	pos;
	int	min;
	int	max;
	int	len;
	int	new_size;
	int	chunk_size;
	int	top_pos;
	int	tail_pos;
	int	*s;
}	t_data;

int	partition(t_data *data, int low, int high);
int	median(t_data *data, int low, int high);
int	chunk_count(t_data *data);
void	chunk_elements(t_list **a, t_list **b, t_data *data);
void	chunk_main(t_list **a, t_list **b, t_data *data);
void	quick_sort(t_data *data, int low, int high);
void	l_index(t_list **stack_a, t_data *data, int argc);
void	ft_swap(int *a, int *b);
void	sort_3(t_list **a);
void	push(t_list **a, t_list **b);
void	swap(t_list **x);
void	rotate(t_list **a);
void	r_rotate(t_list **a);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	radix_sort(t_list **a, t_list **b, t_data *data);

#endif
