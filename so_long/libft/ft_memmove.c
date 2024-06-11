/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:05:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/01/25 20:16:28 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*srclen;
	char	*dstlen;

	srclen = (char *)src;
	dstlen = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	if (dstlen > srclen)
	{
		while (n-- > 0)
		{
			((unsigned char *)dst)[n] = ((unsigned char *) src)[n];
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*int	main(void)
{
	char c[8] = "aaaaaaa";
	char q[5] = "dddd";
	ft_memmove(c, q, 3);
	printf("%s \n", c);
	return (0);
}*/
