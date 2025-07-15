/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:53:23 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/14 18:03:15 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (first->index < second->index && second->index < third->index)
		return ;
	else if (first->index < second->index)
	{
		if (first->index < third->index)
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
	else if (first->index > second->index)
	{
		if (second->index > third->index)
		{
			sa(a);
			rra(a);
		}
		else if (first->index > third->index)
			ra(a);
		else
			sa(a);
		return ;
	}
}
