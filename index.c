/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:10:18 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/14 19:29:45 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void	sort_array(t_data *data)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < data->size - 1)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->s[i] > data->s[j])
			{
				temp = data->s[i];
				data->s[i] = data->s[j];
				data->s[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index(t_list **stack_a, t_data *data)
{
	int		i;
	t_list	*node;

	node = *stack_a;
	while (node != NULL)
	{
		i = 0;
		while (i < data->size)
		{
			if (data->s[i] == node->content)
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}
