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

int	chunk_size(t_data *data)
{
	int	target;

	target = 0;
	if (data->size <= 10)
		target = 2;
	if (data->size <= 100)
		target = 5;
	if (data->size > 100 && data->size <= 250)
		target = 10;
	if (data->size > 250)
		target = 20;
	return (target);
}

void	position(t_list **a, t_data *data)
{
	int	count;
	int	target;
	t_list	*temp;

	count = 0;
	temp = *a;
	target = chunk_size(data);
	while (*)
	while (temp->index <= target)
	{
		
	}
}

void	chunk(t_list **a, t_list **b, t_data *data)
{

}
