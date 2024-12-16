/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:46:28 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/16 18:32:36 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_node(t_data *data)
{
	int	i;
	int	value;

	i = 0;
	while (data->split[i])
	{
		value = ft_ps_atoi(data->split[i], data);
		add_to_list(data, value);
		i++;
	}
}

void	add_to_list(t_data *data, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		error(NULL);
	new->value = value;
	new->next = NULL;
	if (!data->a)
		data->a = new;
	else
	{
		tmp = data->a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}