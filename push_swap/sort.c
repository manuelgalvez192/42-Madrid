/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:30:27 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/23 21:20:16 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_data *data)
{
	if (data->a->value > data->a->next->value)
		swap_a(data);
}

void	sort_3(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->value;
	b = data->a->next->value;
	c = data->a->next->next->value;
	if (a > b && b < c && a < c)
		swap_a(data);
	else if (a > b && b > c)
	{
		swap_a(data);
		rev_rotate_a(data);
	}
	else if (a > b && b < c && a > c)
		rotate_a(data);
	else if (a < b && b > c && a < c)	
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (a < b && b > c && a > c)
		rev_rotate_a(data);
}

void	move_min_to_top(t_data *data)
{
	int	min;
	int	pos;
	int	i;
	t_node *current = data->a;

	min = get_min(data->a);
	pos = 0;
	i = 0;
	while (current)
	{
		if (current->value == min)
			pos = i;
		current = current->next;
		i++;
	}
	if (pos <= data->len_a / 2)
		while (pos--)
			rotate_a(data);
	else
	{
		pos = data->len_a - pos;
		while (pos--)
			rev_rotate_a(data);
	}
}

void	sort_4(t_data *data)
{
	while (data->len_a > 3)
	{
		move_min_to_top(data);
		push_b(data);
	}
	sort_3(data);
	push_a(data);
}

void	sort_5(t_data *data)
{
	while (data->len_a > 4)
	{
		move_min_to_top(data);
		push_b(data);
	}
	sort_4(data);
	push_a(data);
}

