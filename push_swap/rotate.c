/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:19 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/14 16:55:44 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	t_node	*tmp;
	t_node	*last;

	tmp = data->a;
	last = data->a;
	while (last->next)
		last = last->next;
	data->a = data->a->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_data *data)
{
	t_node	*tmp;
	t_node	*last;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	tmp = data->b;
	last = data->b;
	while (last->next)
		last = last->next;
	data->b = data->b->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_printf("rb\n");
}

void	rotate_rr(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
	ft_printf("rr\n");
}
