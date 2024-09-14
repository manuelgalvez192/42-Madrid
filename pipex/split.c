/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:38:57 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/09/14 20:26:32 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	count_words(char const *s, char c)
{
	const char	*aux;
	size_t		count;

	aux = s;
	count = 0;
	while (*aux)
	{
		while (*aux == c && *aux != '\0')
			aux++;
		if (*aux != '\0')
		{
			count++;
			while (*aux && (*aux != c))
				aux++;
		}
	}
	return (count);
}

char	**free_arr(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char	*allocate_word(char const *start, size_t len)
{
	char	*word;

	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

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

char	**ft_split(char const *s, char c)
{
	char		**arr;
	const char	*start;
	size_t		num_words;
	size_t		i;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	arr = (char **)ft_calloc(num_words + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < num_words)
	{
		while (*s == c && *s)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		arr[i] = allocate_word(start, s - start);
		if (!arr[i])
			return (free_arr(arr, i));
	}
	arr[i] = NULL;
	return (arr);
}
