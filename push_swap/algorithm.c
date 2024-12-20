/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:14:47 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/18 17:34:44 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_algo(t_data *data)
{
	if (data->len_a == 2)
		sort_2(data);
	else if (data->len_a == 3)
		sort_3(data);
	else if (data->len_a == 4)
		sort_4(data);
	else if (data->len_a == 5)
		sort_5(data);
	else
		sort_big(data);
}

bool	is_sorted(t_data *data)
{
	t_node	*tmp;

	tmp = data->a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
