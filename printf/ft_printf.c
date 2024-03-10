/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:20:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/02/27 21:14:12 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_print_number.c"
#include <cstdarg>
#include <stdarg.h>

void	print_char(va_list *args)
{
	char	c;
	c = va_arg(*args, char);
	write(1, &c, 1);
}

void	print_string(va_list *args)
{
	char	*c;
	*c = va_arg(*args, char);
	while (*c)
	{
		write(1, c, 1);
	}
}

/*void	print_pointer(va_list *args)
{
	write(1, "0x", 2);
}*/

void	select_case(char const *format, va_list args)
{
	if (*format == 'c')
		print_char(&args);
	else if (*format == 's')
		print_string(&args);
	else if (*format == 'd')
		print_decimal(&args);
	else if (*format == 'p')
		print_pointer(&args);
	else if (*format == 'i')
		print_int(&args);
	else if (*format == 'u')
		print_unsigned_decimal(&args);
	else if (*format == 'x')
		print_hexa_min(&args);
	else if (*format == 'X')
		print_hexa_max(&args);
	else if (*format == '%')
		print_percentage(&args);
		
}

int	ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			select_case(format, args);
		}
		format++;
	}
	va_end(args);
}
