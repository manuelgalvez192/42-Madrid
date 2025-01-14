/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:46:28 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/14 17:02:03 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_node(t_data *data)
{
	int	i;
	int	value;

	i = 0;
	while (data->split[i])
	{
		value = ft_ps_atoi(data->split[i], data);
		add_to_list(data, value);
		i++;
	}
}

void	add_to_list(t_data *data, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		error(NULL);
	new->value = value;
	new->next = NULL;
	if (!data->a)
		data->a = new;
	else
	{
		tmp = data->a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	free(new);
}

void	calculate_length(t_data *data)
{
	t_node	*current;
	int		len_a;
	int		len_b;

	len_a = 0;
	len_b = 0;
	current = data->a;
	while (current)
	{
		len_a++;
		current = current->next;
	}
	current = data->b;
	while (current)
	{
		len_b++;
		current = current->next;
	}
	data->len_a = len_a;
	data->len_b = len_b;
}

void	calculate_index(t_data *data)
{
	t_node	*current;
	t_node	*comparator;
	int		index;

	current = data->a;
	while (current)
	{
		index = 0;
		comparator = data->a;
		while (comparator)
		{
			if (current->value > comparator->value)
				index++;
			comparator = comparator->next;
		}
		current->index = index + 1;
		current = current->next;
	}
}

int	get_min(t_node *a)
{
	t_node	*tmp;
	int		min;

	tmp = a;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}
