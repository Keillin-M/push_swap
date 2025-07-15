/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:19:44 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/15 18:32:12 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position(t_list **a, int target)
{
	int	pos;
	t_list	*temp;

	pos = 0;
	temp = *a;
	while (temp)
	{
		if (temp->index == target)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (-1);
}
