/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:15:36 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/16 13:15:52 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(int max)
{
	int	count;

	count = 0;
	while (max > 0)
	{
		max = max >> 1;
		count++;
	}
	return (count);
}

void	radix_sort(t_list **a, t_list **b, t_data *data)
{
	int	i;
	int	bit;
	int	max;
	int	count;

	i = 0;
	max = max_bits(data->size - 1);
	while (i < max)
	{
		count = data->size;
		while (count > 0)
		{
			bit = ((*a)->index >> i) & 1;
			if (bit == 0)
				pb(a, b);
			if (bit == 1)
				ra(a);
			count--;
		}
		while (*b)
		{
			pa(a, b);
		}
		i++;
	}
}
