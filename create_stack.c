/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:24:06 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/18 17:59:16 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_int(const char *nptr)
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
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > -(long)INT_MIN))
			return (1);
		nptr++;
	}
	if (*nptr != '\0')
		return (1);
	return (0);
}

static int	input_check(t_data *data, int num, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (data->s[j] == num)
			return (1);
		j++;
	}
	data->s[i] = num;
	return (0);
}

static int	create_stack(t_list **a, t_data *data, char **input)
{
	int		i;
	int		num;
	int		*val;
	t_list	*new;

	i = 0;
	while (i < data->size)
	{
		num = ft_atoi(input[i]);
		val = malloc(sizeof(int));
		if (!val)
			return (1);
		*val = num;
		if (input_check(data, num, i))
			return (free(val), 1);
		new = ft_lstnew(val);
		if (!new)
			return (free(val), 1);
		ft_lstadd_back(a, new);
		i++;
	}
	return (0);
}

int	get_input(t_list **a, t_data *data, char **input)
{
	data->size = 0;
	while (input[data->size])
	{
		if (valid_int(input[data->size]))
			return (perror ("Error\n"), 1);
		data->size++;
	}
	data->s = malloc(sizeof(int) * data->size);
	if (!data->s)
		return (perror("Error\n"), 1);
	if (create_stack(a, data, input))
		return (perror ("Error\n"), 1);
	return (0);
}

int	input_join(int argc, char **argv, t_data *data)
{
	int		i;
	char	*temp;
	char	*joined;

	i = 1;
	data->input = ft_strdup("");
	if (!data->input)
		return (1);
	while (i < argc)
	{
		temp = ft_strjoin(argv[i], " ");
		if (!temp)
			return (free(data->input), 1);
		joined = ft_strjoin(data->input, temp);
		free(temp);
		if (!joined)
			return (free(data->input), 1);
		free(data->input);
		data->input = joined;
		i++;
	}
	return (0);
}
