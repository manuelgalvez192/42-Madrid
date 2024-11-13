/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:29 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/13 15:53:48 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_stack *stack)
{
    if (stack->a == NULL)
        return;
    t_node	*temp;
	temp = stack->a;
    stack->a = stack->a->next;
    temp->next = stack->b;
    stack->b = temp;
}

void push_a(t_stack *stack)
{
    if (stack->b == NULL)
        return;
    t_node	*temp;
    temp = stack->b;
    stack->b = stack->b->next;
    temp->next = stack->a;
    stack->a = temp;
}
