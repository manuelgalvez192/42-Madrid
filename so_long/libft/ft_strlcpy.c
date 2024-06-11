/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:39:37 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/01/24 18:02:28 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (size > 0)
	{
		while ((i < size - 1) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclen);
}

/*int	main(void)
{
	char c[5] = "aaaa";
	char q[8] = "bbbbbbb";
	ft_strlcpy(q, c, 3);
	printf("%s \n", q);
	return (0);
}*/
