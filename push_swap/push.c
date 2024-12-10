/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:29 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/10 18:02:50 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_stack *stack)
{
    if (stack->b == NULL)
        return;
    t_node	*temp;
    temp = stack->b;
    stack->b = stack->b->next;
    temp->next = stack->a;
    stack->a = temp;
    ft_printf("pa\n");
}

void push_b(t_stack *stack)
{
    if (stack->a == NULL)
        return;
    t_node	*temp;
	temp = stack->a;
    stack->a = stack->a->next;
    temp->next = stack->b;
    stack->b = temp;
    ft_printf("pb\n");
}
