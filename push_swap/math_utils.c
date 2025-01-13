/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:18:56 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/12 18:33:41 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_sqrt(int n)
{
	double	approx;
	double	better_approx;

	if (n < 0)
		return (-1);
	approx = n / 2.0;
	better_approx = 0.5 * (approx + n / approx);
	while (better_approx != approx)
	{
		approx = better_approx;
		better_approx = 0.5 * (approx + n / approx);
	}
	return (approx);
}

int	calc_k(t_data *data)
{
	int	k;

	k = ft_sqrt(data->len_a) * (7 / 5);
	return (k);
}