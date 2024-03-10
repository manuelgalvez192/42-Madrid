/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:52:00 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/02/27 21:14:15 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <cstdarg>
#include <stdarg.h>

void	print_hexa_min(va_list args)
{
	
}

void	print_hexa_max(va_list args)
{

}

void	print_decimal(va_list args)
{
    char	*c;
	*c = va_arg(*args, char);
	ft_itoc(*c);
	while (*c)
	{
		write(1, c, 1);
	}
}

void	print_int(va_list args)
{
	char	*c;
	*c = va_arg(*args, char);
	ft_itoc(*c);
	while (*c)
	{
		write(1, c, 1);
	}
}
