/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:56:28 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/23 10:21:52 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	handle_args(int argc, char **argv, t_list **a, t_data *data)
{
	char	**input;

	input = NULL;
	data->input = NULL;
	if (argc < 2)
		return (1);
	if (argc > 2)
	{
		if (input_join(argc, argv, data))
			return (1);
		input = ft_split(data->input, ' ');
	}
	else if (argc == 2)
		input = ft_split(argv[1], ' ');
	if (!input)
		return (1);
	if (get_input(a, data, input))
		return (free_array(input), 1);
	free_array(input);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	data;

	data.s = NULL;
	a = NULL;
	b = NULL;
	if (handle_args(argc, argv, &a, &data))
		ft_exit(&a, &b, &data);
	l_index(&a, &data);
	if (is_sorted(a))
		ft_exit(&a, &b, &data);
	if (ft_lstsize(a) <= 5)
		sort_small(&a, &b);
	else
		chunk_main(&a, &b, &data);
	ft_exit(&a, &b, &data);
	return (0);
}
