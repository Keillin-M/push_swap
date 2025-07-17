/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:15:58 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/16 17:39:51 by kmaeda           ###   ########.fr       */
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
		target = 20;
	return (target);
}

int	position(t_list **a, t_data *data)
{
	int	i;
	t_list	*first;
	t_list	*last;

	i = 0;
	first = *a;
	last = first;
	data->top_pos = -1;
	data->tail_pos = -1;
	while (last != NULL && i < data->new_size)
	{
		if (last->index >= data->min && last->index < data->max)
			data->tail_pos = i;
		i++;
		last = last->next;
	}
	while (first != NULL && first->index >= data->min && first->index < data->max)
	{
		data->top_pos++;
		first = first->next;
	}
	if (data->top_pos != -1 && data->tail_pos != -1 && data->top_pos < data->tail_pos)
		return (1);
	else
		return (0);
	return (-1);
}

int	chunk_part(t_list **a, t_list **b, t_data *data)
{
	int	pos;

	pos = position(a, data);
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

void	chunk_sort(t_list **a, t_list **b, t_data *data)
{
	int	found;
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

void	chunk(t_list **a, t_list **b, t_data *data)
{
	int	i;
	int	chunks;
	int	remainder;

	i = 0;
	chunks = chunk_count(data);
	remainder = data->size % chunks;
	data->chunk_size = data->size / chunks;
	while (i < chunks - 1)
	{
		if (i < remainder)
		{
			data->min = i * data->chunk_size;
			data->max = (i + 1) * data->chunk_size + 1;
		}
		else
		{
			data->min = i * data->chunk_size;
			data->max = (i + 1) * data->chunk_size;
		
		}
		chunk_sort(a, b, data);
		i++;
	}
// call function to sort a (last chunk left)
	// find the biggest in B, using rotate and rr to bring back, then push to a
}
