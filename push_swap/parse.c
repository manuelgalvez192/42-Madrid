/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:10:44 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/16 23:24:10 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_str(char	*str, t_data *data)
{
	if (*str == '\0')
		error(data);
	data->split = ft_split(str, ' ');
	call_check_fill(data);
}

void	parse_args(char *str, t_data *data, int i)
{
	if (*str == '\0')
		error(data);
	data->split[i] = ft_strdup(str);
}
