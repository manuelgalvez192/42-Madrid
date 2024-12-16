/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:10:44 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/16 18:34:58 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_str(char	*str, t_data *data)
{
	if (*str == '\0')
		error(NULL);
	data->split = ft_split(str, ' ');
	call_check_fill(data);
}

void	parse_args(char *str, t_data *data, int i)
{
	if (*str == '\0')
		error(NULL);
	data->split[i] = ft_strdup(str);
}
