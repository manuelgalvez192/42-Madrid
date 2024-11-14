/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:52:00 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/14 15:35:07 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(size_t num, char *hex_digits, int *len)
{
	if (num >= 16)
		print_hexa((num / 16), hex_digits, len);
	ft_putchar(hex_digits[num % 16], len);
}

void	print_decimal(int num, int *len)
{
	unsigned int	num2;

	num2 = 0;
	if (num < 0)
	{
		ft_putchar('-', len);
		num2 = -num;
	}
	else
		num2 = num;
	if (num2 >= 10)
		print_decimal(num2 / 10, len);
	ft_putchar(num2 % 10 + '0', len);
}

void	print_unsigned(unsigned int num, int *len)
{
	unsigned int	digit;

	digit = 0;
	if (num >= 10)
		print_unsigned(num / 10, len);
	digit = num % 10 + '0';
	ft_putchar(digit, len);
}
