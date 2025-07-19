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

void	free_array(char **array)
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

void	free_stack(t_list **stack)
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

int	handle_args(int argc, char **argv, t_list **a, t_data *data)
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
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;

	data.s = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (handle_args(argc, argv, &stack_a, &data))
		return (1);
	l_index(&stack_a, &data);
	if (ft_lstsize(stack_a) == 3)
	{
		sort_3(&stack_a);
		return (0);
	}
	chunk_main(&stack_a, &stack_b, &data);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (argc > 2)
		free(data.input);
	if (data.s)
		free(data.s);
	return (0);
}
