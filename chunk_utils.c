/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:15:58 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/18 14:08:38 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_count(t_data *data)
{
	int	target;

	target = 0;
	if (data->size <= 10)
		target = 2;
	else if (data->size <= 100)
		target = 5;
	else if (data->size <= 250)
		target = 10;
	else if (data->size > 250)
		target = 15;
	return (target);
}

static void	pos_first(t_list **a, t_data *data)
{
	int		i;
	t_list	*first;

	i = 0;
	first = *a;
	data->top_pos = -1;
	while (first != NULL)
	{
		if (first->index >= data->min && first->index < data->max)
		{
			data->top_pos = i;
			break ;
		}
		i++;
		first = first->next;
	}
	return ;
}

static int	pos_cost(t_list **a, t_data *data)
{
	int		i;
	t_list	*last;

	i = 0;
	last = *a;
	data->tail_pos = -1;
	while (last != NULL)
	{
		if (last->index >= data->min && last->index < data->max)
			data->tail_pos = i;
		i++;
		last = last->next;
	}
	pos_first(a, data);
	if (data->top_pos == -1 && data->tail_pos == -1)
		return (-1);
	else if (data->top_pos <= data->tail_pos)
		return (1);
	else
		return (0);
}

static int	chunk_part(t_list **a, t_list **b, t_data *data)
{
	int	pos;

	pos = pos_cost(a, data);
	if (pos < 0)
		return (1);
	else if (pos == 1)
	{
		while (data->top_pos > 0)
		{
			ra(a);
			data->top_pos--;
		}
		pb(a, b);
	}
	else if (pos == 0)
	{
		while (data->tail_pos > 0)
		{
			rra(a);
			data->tail_pos--;
		}
		pb(a, b);
	}
	return (0);
}

void	chunk_elements(t_list **a, t_list **b, t_data *data)
{
	int		found;
	t_list	*temp;

	data->new_size = data->max - data->min;
	while (1)
	{
		temp = *a;
		found = 0;
		while (temp)
		{
			if (temp->index >= data->min && temp->index < data->max)
			{
				found = 1;
				break ;
			}
			temp = temp->next;
		}
		if (!found)
			break ;
		chunk_part(a, b, data);
	}
}
