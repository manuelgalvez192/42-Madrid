/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/26 13:08:11 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *stack) {
    while (stack) {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    ft_printf("NULL\n");
}

int	main(int argc, char **argv)
{
    if (argc < 2 || argc > 2)
        error();
    parse(argv[1]);
    
    return 0;
}
