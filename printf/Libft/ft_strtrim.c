/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:59:49 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/02/01 19:25:14 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_char(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*ini;
	char	*fin;
	size_t	ptrlen;

	if (!s1 || !set)
		return (0);
	ini = (char *)s1;
	while (*ini && ft_find_char(*ini, set))
		ini++;
	fin = (char *)s1 + ft_strlen(s1) - 1;
	while ((fin > ini) && ft_find_char(*fin, set))
		fin--;
	ptrlen = fin - ini + 1;
	ptr = ft_calloc((ptrlen + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, ini, ptrlen + 1);
	return (ptr);
}
