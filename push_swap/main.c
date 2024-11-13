/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/13 18:19:04 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *stack) {
    while (stack) {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}

int	main(void)
{
    t_node node5 = {5, NULL};
    t_node node4 = {4, &node5};
	t_node node3 = {3, &node4};
    t_node node2 = {2, &node3};
    t_node node1 = {1, &node2};

    t_stack stacks;
    stacks.a = &node1;
    stacks.b = NULL;

    printf("\nAntes de rotate a:\n");
    printf("Pila 'a': ");
    print_stack(stacks.a);
    printf("Pila 'b': ");
    print_stack(stacks.b);

    rotate_a(&stacks);

    printf("\nDespués de rotate a:\n");
    printf("Pila 'a': ");
    print_stack(stacks.a);
    printf("Pila 'b': ");
    print_stack(stacks.b);
    
    return 0;
}

