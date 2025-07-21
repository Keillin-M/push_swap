/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:53:23 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/21 17:39:59 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_mov(t_list **a, t_list *first, t_list *second, t_list *third)
{
	if (first->index < second->index)
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

static void	sort_3(t_list **a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (first->index < second->index && second->index < third->index)
		return ;
	else
		sort_3_mov(a, first, second, third);
}

static void	sort_4(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if ((*a)->index == 0)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	sort_3(a);
	pa(a, b);
}

static void	sort_5(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	sort_3(a);
	while (*b)
	{
		pa(a, b);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}

void	sort_small(t_list **a, t_list **b)
{
	int	n;

	n = ft_lstsize(*a);
	if (n == 3)
		sort_3(a);
	if (n == 4)
		sort_4(a, b);
	if (n == 5)
		sort_5(a, b);
}
