/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:21:32 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/14 15:35:52 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(size_t num, char *hex_digits, int *len)
{
	ft_putstr("0x", len);
	print_hexa(num, hex_digits, len);
}
