/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:29 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/13 02:42:30 by mgalvez-         ###   ########.fr       */
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
    data->len_a++;
    data->len_b--;
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
    data->len_a--;
    data->len_b++;
    ft_printf("pb\n");
}
