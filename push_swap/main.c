/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:52 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/23 17:38:46 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (free(data), 0);	
	if (argc == 2)
		parse_str(argv[1], data);
	else
	{
		data->split = ft_calloc(argc, sizeof(char *));
		if (!data->split)
			error(NULL);
		while (i < argc)
		{
			parse_args(argv[i], data, i - 1);
			i++;
		}
		call_check_fill(data);
	}
	sorting_functions(data);
	return (0);
}

void	sorting_functions(t_data *data)
{
	if (is_sorted(data))
	 	return ;
	calculate_index(data);
	calculate_length(data);
	start_algo(data);
	free_split(data->split);
	free_list(data->a);
	free_list(data->b);
	free(data);
}
