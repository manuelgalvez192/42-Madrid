/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:30:27 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/20 13:37:30 by mgalvez-         ###   ########.fr       */
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

void	sort_4(t_data *data)
{
	int	min;

	min = get_min(data->a);
	while (data->len_a > 3)
	{
		if (data->a->value == min)
			push_b(data);
		else
			rotate_a(data);
	}
	sort_3(data);
	push_a(data);
}

void	sort_5(t_data *data)
{
	int	min;

	min = get_min(data->a);
	while (data->len_a > 4)
	{
		if (data->a->value == min)
			push_b(data);
		else
			rotate_a(data);
	}
	sort_4(data);
	push_a(data);
	push_a(data);
}
