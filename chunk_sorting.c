/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:02:34 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/18 14:09:10 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_list **b)
{
	int		max;
	t_list	*temp;

	max = -1;
	temp = *b;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

static void	chunk_mov(t_list **a, t_list **b, t_data *data, int pos)
{
	int	i;

	i = data->len - data->pos;
	if (pos == 1)
	{
		while (data->pos != 0 && data->len > 0)
		{
			rb(b);
			data->pos--;
		}
		pa(a, b);
	}
	else if (pos == 0)
	{
		while (i > 0 && data->len > 0)
		{
			rrb(b);
			i--;
		}
		pa(a, b);
	}
}

static int	close_pos(t_list **b, t_data *data)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *b;
	data->pos = -1;
	while (temp)
	{
		if (temp->index == data->target)
		{
			data->pos = i;
			break ;
		}
		i++;
		temp = temp->next;
	}
	if (data->pos == -1)
		return (-1);
	else if (data->pos <= data->len / 2)
		return (1);
	else
		return (0);
}

static void	chunk_sort(t_list **a, t_list **b, t_data *data)
{
	int	pos;

	while (*b)
	{
		data->len = ft_lstsize(*b);
		data->target = get_max_index(b);
		pos = close_pos(b, data);
		if (pos < 0)
			return ;
		chunk_mov(a, b, data, pos);
	}
}

void	chunk_main(t_list **a, t_list **b, t_data *data)
{
	int	i;
	int	chunks;
	int	remainder;

	i = 0;
	chunks = chunk_count(data);
	remainder = data->size % chunks;
	data->chunk_size = data->size / chunks;
	while (i < chunks)
	{
		if (i < remainder)
		{
			data->min = i * (data->chunk_size + 1);
			data->max = data->min + data->chunk_size + 1;
		}
		else
		{
			data->min = i * data->chunk_size + remainder;
			data->max = data->min + data->chunk_size;
		}
		chunk_elements(a, b, data);
		i++;
	}
	chunk_sort(a, b, data);
}
