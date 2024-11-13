/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:19 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/13 19:00:34 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	tmp = stack->b;
	last = stack->a;
	while (last->next)
		last = last->next;
	stack->a = stack->a->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rotate_b(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	tmp = stack->b;
	last = stack->b;
	while (last->next)
		last = last->next;
	stack->b = stack->b->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rotate_rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
