/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:35:11 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/02/27 20:44:12 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>

#include "libft.h"

# define	HEX_DIGITS_MIN "0123456789abcdef"
# define	HEX_DIGITS_MAX "0123456789ABCDEF"

int	ft_printf(char const *, ...);

#endif
