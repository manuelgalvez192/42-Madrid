/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:35:11 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/03/15 19:23:38 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
void	select_case(char const *format, va_list args, int *len);
void	print_hexa(size_t num, char *hex_digits, int *len);
void	print_decimal(int num, int *len);
void	print_unsigned(unsigned int num, int *len);
void	print_pointer(size_t num, char *hex_digits, int *len);

#endif
