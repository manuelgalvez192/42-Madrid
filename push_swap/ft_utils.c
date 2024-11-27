/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:34:21 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/27 13:35:08 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

int	ft_ps_atoi(const char *str)
{
	int	pos;
	int	total;
	int	sing;

	total = 0;
	sing = 1;
	pos = 0;
	while (str[pos] == ' ' || (str[pos] >= 9 && str[pos] <= 13))
		pos++;
	if (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '+')
			sing = 1;
		else
			sing = -1;
		pos++;
	}
	if (str[pos] == '\0')
		return (0);
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		total = total * 10 + (str[pos] - '0');
		pos++;
	}
	return (total * sing);
}

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
