/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:05:43 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/01/20 21:03:12 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*strlast;

	strlast = NULL;
	while (*s)
	{
		if (*s == (char)c)
			strlast = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)strlast);
}

/*int	main(void)
{
	char *c = "abcdefghcxyz";
	char *q = "abcdefghcxyz";
	printf("%s \n", ft_strrchr(c, 'c'));
	printf("%s \n", strrchr(q, 'c'));
	return (0);
}*/
