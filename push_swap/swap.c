/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:22 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/15 12:55:05 by mgalvez-         ###   ########.fr       */
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
	ft_printf("sa\n");
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
	ft_printf("sb\n");
}

void	swap_ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	ft_printf("ss\n");
}
