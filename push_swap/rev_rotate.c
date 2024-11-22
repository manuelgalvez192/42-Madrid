/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:16 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/14 13:49:08 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	tmp = stack->a;
	last = stack->a;
	while (last->next->next)
		last = last->next;
	stack->a = last->next;
	stack->a->next = tmp;
	last->next = NULL;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	tmp = stack->b;
	last = stack->b;
	while (last->next->next)
		last = last->next;
	stack->b = last->next;
	stack->b->next = tmp;
	last->next = NULL;
	ft_printf("rrb\n");
}

void	rev_rotate_rrr(t_stack *stack)
{
	rev_rotate_a(stack);
	rev_rotate_b(stack);
	ft_printf("rrr\n");
}
