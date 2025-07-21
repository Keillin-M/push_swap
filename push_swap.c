/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:56:28 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/18 14:09:53 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = temp;
	}
}

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
		return (1);
	l_index(&a, &data);
	if (is_sorted(a))
		return (free_stack(&a), free(data.s), 1);
	if (ft_lstsize(a) <= 5)
		return (sort_small(&a, &b), free_stack(&a), free(data.s), 0);
	chunk_main(&a, &b, &data);
	free_stack(&a);
	free_stack(&b);
	if (argc > 2)
		free(data.input);
	if (data.s)
		free(data.s);
	return (0);
}
