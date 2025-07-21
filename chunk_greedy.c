/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:59:49 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/21 14:02:39 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_greedy(t_list **a, t_list **b, t_data *data)
{
	int	index;

	index = (*a)->index;
	pb(a, b);
	if (index < data->min + (data->chunk_size / 2))
		rb(b);
}
