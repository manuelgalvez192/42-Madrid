/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:36:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/01/20 21:03:40 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

/*int	main(void)
{
	char *c = "abcdefgh";
	char *q = "abcdefgh";
	printf("%s \n", ft_strchr(c, '\0'));
	printf("%s \n", strchr(q, '\0'));
	return (0);
}*/
