/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:34:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/16 18:39:54 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_check_fill(t_data *data)
{
	check_digits(data);
	fill_node(data);
	check_repeated(data);
}

void	check_digits(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if ((data->split[i][j] == '-' || data->split[i][j] == '+') && j == 0)
				j++;
			if (!ft_isdigit(data->split[i][j]))
				error(data);
			j++;
		}
		i++;
	}
}

void	check_repeated(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = i + 1;
		while (data->split[j])
		{
			if (ft_strncmp(data->split[i], data->split[j]) == 0)
				error(data);
			j++;
		}
		i++;
	}
}
