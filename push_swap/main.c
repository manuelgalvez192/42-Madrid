/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/18 16:57:24 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack_with_indices(t_node *stack) {
    while (stack) {
        printf("Value: %d, Index: %d\n", stack->value, stack->index);
        stack = stack->next;
    }
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	i = 1;
	data = malloc(sizeof(t_data));
	data->a = NULL;
	data->b = NULL;
	data->split = NULL;
	if (argc < 2)
		error(NULL);
	if (argc == 2)
		parse_str(argv[1], data);
	else
	{
		data->split = malloc(sizeof(char *) * (argc));
		while (i < argc)
		{
			parse_args(argv[i], data, i - 1);
			i++;
		}
		call_check_fill(data);
	}
	if (is_sorted(data))
		return 0;
	calculate_index(data);
	print_stack_with_indices(data->a);
	return 0;
}
