/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:10:44 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/11 19:02:42 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_str(char	*str, t_data *data)
{
	if (*str == '\0')
		error(NULL);
	data->split = ft_split(str, ' ');
	check_digits(data);
	fill_node(data);
}

void	parse_args(char *str, t_data *data, int i)
{
	if (*str == '\0')
		error(NULL);
	data->split[i] = ft_strdup(str);
	ft_printf("---------------- %s\n", data->split[i]);
	check_digits(data);
	fill_node(data);
}

void	check_digits(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		ft_printf("++++++++++++++++++++ %s\n", data->split[i]);
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
