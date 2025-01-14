/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:16 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/14 16:47:33 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_data *data)
{
	t_node	*tmp;
	t_node	*last;

	tmp = data->a;
	last = data->a;
	while (last->next->next)
		last = last->next;
	data->a = last->next;
	data->a->next = tmp;
	last->next = NULL;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_data *data)
{
	t_node	*tmp;
	t_node	*last;

	tmp = data->b;
	last = data->b;
	if (data->b == NULL || data->b->next == NULL)
		return ;
	while (last->next->next)
		last = last->next;
	data->b = last->next;
	data->b->next = tmp;
	last->next = NULL;
	ft_printf("rrb\n");
}

void	rev_rotate_rrr(t_data *data)
{
	rev_rotate_a(data);
	rev_rotate_b(data);
	ft_printf("rrr\n");
}
