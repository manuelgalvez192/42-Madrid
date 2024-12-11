/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/11 19:02:25 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node)
{
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
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
		while (i < argc)
		{
			data->split = malloc(sizeof(char *) * (argc - 1));
			parse_args(argv[i], data, i - 1);
			i++;
		}
	}
	print_node(data->a);
	return 0;
}
