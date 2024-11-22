/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:28:01 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/15 12:28:07 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		total = total * 10 + (str[pos] - '0');
		pos++;
	}
	return (total * sing);
}