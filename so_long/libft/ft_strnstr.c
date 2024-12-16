/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:04:37 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/16 19:00:06 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*haystack_tem;
	const char	*needle_tem;
	size_t		i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = len;
		haystack_tem = haystack;
		needle_tem = needle;
		while (i-- > 0 && *haystack_tem && *needle_tem
			&& *haystack_tem == *needle_tem)
		{
			haystack_tem++;
			needle_tem++;
		}
		if (*needle_tem == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
