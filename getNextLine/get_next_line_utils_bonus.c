/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:44:50 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/05/27 19:44:55 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_strjoin_internal(char *dest, const char *src, size_t *i)
{
	size_t	j;

	j = 0;
	while (src[j])
		dest[(*i)++] = src[j++];
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s2)
		s2 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
	{
		free(s1);
		free((char *)s2);
		return (NULL);
	}
	ft_strjoin_internal(result, s1, &i);
	ft_strjoin_internal(result, s2, &i);
	result[i] = '\0';
	free(s1);
	return (result);
}

void	ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;

	p = ptr;
	while (num--)
		*p++ = (unsigned char)value;
}
