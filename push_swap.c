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

	while(*stack)
	{
		temp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = temp;
	}
}

int	handle_args(int argc, char **argv, t_list **a, t_data *data)
{
	char ** input = NULL;

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
	if (argc == 4)
	{
		sort_3(a);
		return (free_array(input), 0);
	}
	free_array(input);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_data	data;
	t_list	*temp;

	data.s = NULL;
	if (handle_args(argc, argv, &stack_a, &data))
		return (1);
	l_index(&stack_a, &data);
	chunk_main(&stack_a, &stack_b, &data);
	temp = stack_a;
	while (temp)
	{
		ft_printf("Value[%d]: %d\n", temp->index, *(int *)temp->content);
		temp = temp->next;
	}
	while (stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (argc > 2)
		free(data.input);
	if (data.s)
		free(data.s);
	return (0);
}
