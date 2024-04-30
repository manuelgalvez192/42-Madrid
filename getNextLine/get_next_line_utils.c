/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:17:53 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/04/26 20:38:21 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = ft_calloc(((s1len + s2len) + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcat(ptr, s1, s1len + 1);
	ft_strlcat(ptr, s2, s2len + s1len + 1);
	free ((char *)s1);
	free ((char *)s2);
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	len;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstsize > dstlen)
		len = srclen + dstlen;
	else
		len = srclen + dstsize;
	while (src[i] && dstsize > (dstlen + 1))
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = size * count;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	while (len > 0)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
		len--;
	}
	return ((unsigned char *)ptr);
}
