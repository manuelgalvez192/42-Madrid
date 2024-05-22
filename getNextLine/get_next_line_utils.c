/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:32:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/05/15 19:32:10 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
char	*ft_strjoin(char const *s1, char const *s2, int flag)
{
	char	*aux_s1;
	int		i;
	int		j;

	aux_s1 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux_s1 || !s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		aux_s1[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		aux_s1[i++] = s2[j++];
	aux_s1[i] = '\0';
	if (flag == 1)
		free ((char *)s1);
	return (aux_s1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = size * count;
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (len > 0)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
		len--;
	}
	return ((unsigned char *)ptr);
}

char	*free_null(char **buffer, char **new_line)
{
	if (*new_line)
		free (*new_line);
	*new_line = NULL;
	if (*buffer)
		free (*buffer);
	*buffer = NULL;
	return (NULL);
}
