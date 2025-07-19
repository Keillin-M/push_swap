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

static void	chunk_mov(t_list **a, t_list **b, t_data *data, int pos)
{
	int	i;

	if (pos == 1)
	{
		while (data->pos > 0 && data->len > 1)
		{
			rb(b);
			data->pos--;
		}
		pa(a, b);
	}
	else if (pos == 0)
	{
		i = data->target - data->pos;
		while (i > 0 && data->len > 1)
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
		if (temp->index == data->target - 1)
		{
			data->pos = i;
			break ;
		}
		i++;
		data->target--;
		temp = temp->next;
	}
	if (data->pos == -1)
		return (-1);
	else if (data->pos < data->target / 2)
		return (1);
	else
		return (0);
}

static void	chunk_sort(t_list **a, t_list **b, t_data *data)
{
	int	pos;

	data->target = data->size;
	while (*b)
	{
		data->len = ft_lstsize(*b);
		pos = close_pos(b, data);
		if (pos < 0)
			return ;
		else
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
			data->min = i * data->chunk_size;
			data->max = (i + 1) * data->chunk_size + 1;
		}
		else
		{
			data->min = i * data->chunk_size;
			data->max = (i + 1) * data->chunk_size;
		}
		chunk_elements(a, b, data);
		i++;
	}
	chunk_sort(a, b, data);
}
