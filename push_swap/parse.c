/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:10:44 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/10 18:10:16 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(char	*str, t_stack *stack)
{
	char	**split;

	if (*str == '\0')
		error(NULL);
	split = ft_split(str, ' ');
	check_digits(split);
	fill_stack(split, stack);
}

void	check_digits(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if ((split[i][j] == '-' || split[i][j] == '+') && j == 0)
				j++;
			if (!ft_isdigit(split[i][j]))
				error(split);
			j++;
		}
		i++;
	}
}

void	fill_stack(char **split, t_stack *stack)
{
	int	i;

	i = 0;
	while (split[i])
	{
		stack->a = ft_ps_atoi(split[i], split);
		i++;
	}
}
