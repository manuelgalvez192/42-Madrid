/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:22 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/18 17:03:47 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	t_node	*tmp;

	if (data->len_a < 2)
		return ;
	if (data->a && data->a->next)
	{
		tmp = data->a->next;
		data->a->next = tmp->next;
		tmp->next = data->a;
		data->a = tmp;
	}
	ft_printf("sa\n");
}

void	swap_b(t_data *data)
{
	t_node	*tmp;

	if (data->len_b < 2)
		return ;
	if (data->b && data->b->next)
	{
		tmp = data->b->next;
		data->b->next = tmp->next;
		tmp->next = data->b;
		data->b = tmp;
	}
	ft_printf("sb\n");
}

void	swap_ss(t_data *data)
{
	swap_a(data);
	swap_b(data);
	ft_printf("ss\n");
}
