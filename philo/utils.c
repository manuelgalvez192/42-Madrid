/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:28:59 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/30 17:42:28 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = size * count;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	while (len > 0)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
		len--;
	}
	return ((unsigned char *)ptr);
}

int	ft_atoi(const char *str)
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
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		total = total * 10 + (str[pos] - '0');
		pos++;
	}
	return (total * sing);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}
