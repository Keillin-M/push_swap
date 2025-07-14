/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:58:20 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/14 11:59:29 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_front(a, temp);
}

void	swap(t_list **x)
{
	t_list	*first;
	t_list	*second;

	if (*x == NULL || (*x)->next == NULL)
		return ;
	first = *x;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*x = second;
}

void	rotate(t_list **a)
{
	t_list	*first;

	if (*a == NULL)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	ft_lstadd_back(a, first);
}

void	r_rotate(t_list **a)
{
	t_list	*last;
	t_list	*second_last;

	last = ft_lstlast(a);
	second_last = *a;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	ft_lstadd_front(a, last);
}
