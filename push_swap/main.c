/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/10 18:05:29 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	
	i = 1;
	if (argc < 2)
		error(NULL);
	if (argc == 2)
		parse(argv[1], stack);
	else
	{
		while (i < argc)
		{
			parse(argv[i], stack);
			i++;
		}
	}
	return 0;
}
