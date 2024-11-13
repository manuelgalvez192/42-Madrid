/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:22 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/13 15:51:36 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a->next;
		stack->a->next = tmp->next;
		tmp->next = stack->a;
		stack->a = tmp;
	}
}

void	swap_b(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b && stack->b->next)
	{
		tmp = stack->b->next;
		stack->b->next = tmp->next;
		tmp->next = stack->b;
		stack->b = tmp;
	}
}

void	swap_ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
