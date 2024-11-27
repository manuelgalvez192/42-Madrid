/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:10:44 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/27 13:49:55 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(char	*str)
{
	char	**split;
	int		*stack;

	if (*str == '\0')
		error();
	split = ft_split(str, ' ');
	check_digits(split);
	stack = NULL;
	stack = fill_stack(split, stack);
	check_max_int(stack);
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
			if (split[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(split[i][j]))
				error();
			j++;
		}
		i++;
	}
}

int	*fill_stack(char **split, int *stack)
{
	int	i;

	stack = malloc(sizeof(int *) * ft_split_len(split + 1));
	if (!stack)
		error();
	i = 0;
	while (split[i])
	{
		stack[i] = ft_ps_atoi(split[i]);
		ft_printf("%d\n", i);
		i++;
	}
	return (stack);
}

void	check_max_int(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		ft_printf("%d\n", stack[i]);
		// if (stack[i] > 2147483647 || stack[i] < -2147483648)
		// 	error();
		i++;
	}
}
