/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:20:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/03/13 19:47:27 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	int	count;

	if (!str)
		return (ft_putstr("(null)", len));
	count = 0;
	while (str[count])
		ft_putchar(str[count++], len);
}

void	select_case(char const *format, va_list args, int *len)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (*format == 'd' || *format == 'i')
		print_decimal(va_arg(args, int), len);
	else if (*format == 'p')
		print_pointer(va_arg(args, size_t), "0123456789abcdef", len);
	else if (*format == 'u')
		print_unsigned(va_arg(args, unsigned int), len);
	else if (*format == 'x')
		print_hexa(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (*format == 'X')
		print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	else if (*format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			select_case(format, args, &len);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
