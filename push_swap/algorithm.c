/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:14:47 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/23 16:54:48 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_algo(t_data *data)
{
	if (data->len_a == 2)
		sort_2(data);
	else if (data->len_a == 3)
		sort_3(data);
	else if (data->len_a == 4)
		sort_4(data);
	else if (data->len_a == 5)
		sort_5(data);
	else	
		k_sort(data);
}

void	k_sort(t_data *data)
{
	int	k;

	k = calc_k(data);
	while (data->len_a > 0)
	{
		if (data->a->index <= data->len_b)
			push_b(data);
		else if (data->a->index <= (data->len_b + k))
		{
			push_b(data);
			rotate_b(data);
		}
		else
			rotate_a(data);
	}
	while (data->len_b > 0)
		check_highest(data);
}

void	check_highest(t_data *data)
{
	t_node	*current;
	int		max_index;
	int		max_position;
	int		position;

	current = data->b;
	max_index = -1;
	max_position = 0;
	position = 0;
	while (current != NULL)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_position = position;
		}
		current = current->next;
		position++;
	}
	move_highest_to_top(data, max_position);
}

void	move_highest_to_top(t_data *data, int max_position)
{
	int		stack_size;

	stack_size = data->len_b;
	if (max_position <= stack_size / 2)
	{
		while (max_position-- > 0)
			rotate_b(data);
	}
	else
	{
		max_position = stack_size - max_position;
		while (max_position-- > 0)
			rev_rotate_b(data);
	}
	push_a(data);
}

bool	is_sorted(t_data *data)
{
	t_node	*tmp;

	tmp = data->a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	free_split(data->split);
	free_list(data->a);
	free_list(data->b);
	free(data);
	return (true);
}
