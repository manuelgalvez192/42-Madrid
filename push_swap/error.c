/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/16 23:13:05 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_data *data)
{
	if (data->split)
		free_split(data->split);
	if (data->a)
		free_list(data->a);
	if (data->b)
		free_list(data->b);
	free(data);
	ft_printf("Error\n");
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void free_list(t_node *list)
{
    t_node *temp;

    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}
