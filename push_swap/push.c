/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:29 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/11 17:37:46 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_data *data)
{
    if (data->b == NULL)
        return;
    t_node	*temp;
    temp = data->b;
    data->b = data->b->next;
    temp->next = data->a;
    data->a = temp;
    ft_printf("pa\n");
}

void push_b(t_data *data)
{
    if (data->a == NULL)
        return;
    t_node	*temp;
	temp = data->a;
    data->a = data->a->next;
    temp->next = data->b;
    data->b = temp;
    ft_printf("pb\n");
}
