/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:23:33 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/01/31 17:51:57 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (ptr);
}
