/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:34:21 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/17 17:24:02 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_atoi(const char *str, t_data *data)
{
	int		pos;
	long	total;
	int		sign;

	total = 0;
	sign = 1;
	pos = 0;
	while (str[pos] == ' ' || (str[pos] >= 9 && str[pos] <= 13))
		pos++;
	if (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '-')
			sign = -1;
		pos++;
	}
	if (str[pos] == '\0')
		return (0);
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		total = total * 10 + (str[pos] - '0');
		if ((total > INT_MAX) || ((total * -1) < INT_MIN))
			error(data);
		pos++;
	}
	return (total * sign);
}

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
