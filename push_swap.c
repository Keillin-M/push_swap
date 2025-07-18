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

int	valid_int(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && result > 2147483648))
			return (1);
		nptr++;
	}
	if (*nptr != '\0')
		return (1);
	return (0);
}

int	input_check(t_data *data, int num, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (data->s[j] == num)
		{
			free(data->s);
			return (1);
		}
		j++;
	}
	data->s[i] = num;
	return (0);
}

int	get_input(int argc, char **argv, t_list **stack_a, t_data *data)
{
	int		i;
	int		num;
	int	*val;
	t_list	*new;

	data->s = malloc(sizeof(int) * (argc - 1));
	if (!data->s)
		return (perror("Error\n"), 1);
	i = 0;
	while (i < argc - 1)
	{
		if (valid_int(argv[i + 1]))
			return (perror ("Error\n"), 1);
		num = ft_atoi(argv[i + 1]);
		val = malloc(sizeof(int));
		*val = num;
		if (input_check(data, num, i))
			return (perror ("Error\n"), 1);
		new = ft_lstnew(val);
		if (!new)
			return (perror ("Error\n"), 1);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_data	data;
	t_list	*temp;

	if (argc < 2)
		return (1);
	if (get_input(argc, argv, &stack_a, &data))
		return (1);
	l_index(&stack_a, &data, argc);
	if (argc == 4)
	{
		sort_3(&stack_a);
		return (0);
	}
	if (argc > 4)
	{
		chunk_main(&stack_a, &stack_b, &data);
		return (0);
	}
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
	free(data.s);
	return (0);
}
