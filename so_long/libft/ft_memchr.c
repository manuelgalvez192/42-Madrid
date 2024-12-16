/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:03:54 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/16 18:59:22 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*strloop;

	i = 0;
	strloop = (unsigned char *)s;
	while (n--)
	{
		if (strloop[i] == (unsigned char)c)
			return (&strloop[i]);
		i++;
	}
	return (NULL);
}
