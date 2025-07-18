/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:18:15 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/15 12:13:41 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(t_data *data, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = data->s[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (i <= high - 1 && data->s[i] <= pivot)
			i++;
		while (j >= low + 1 && data->s[j] > pivot)
			j--;
		if (i < j)
			ft_swap(&data->s[i], &data->s[j]);
	}
	ft_swap(&data->s[low], &data->s[j]);
	return (j);
}

int	median(t_data *data, int low, int high)
{
	int	mid;
	int	a;
	int	b;
	int	c;

	mid = low + (high - low) / 2;
	a = data->s[low];
	b = data->s[mid];
	c = data->s[high];
	if ((a > b) != (a > c))
		return (low);
	else if ((b < a) != (b < c))
		return (mid);
	else
		return (high);
}

void	quick_sort(t_data *data, int low, int high)
{
	int	index;
	int	p_index;

	if (low < high)
	{
		index = median(data, low, high);
		ft_swap(&data->s[index], &data->s[low]);
		p_index = partition(data, low, high);
		quick_sort(data, low, p_index - 1);
		quick_sort(data, p_index + 1, high);
	}
}

void	l_index(t_list **stack_a, t_data *data)
{
	int		i;
	t_list	*node;
	
	node = *stack_a;
	quick_sort(data, 0, data->size - 1);
	node = *stack_a;
	while (node != NULL)
	{
		i = 0;
		while (i < data->size)
		{
			if (data->s[i] == *(int *)node->content)
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}
