/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:15:15 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/01/25 20:19:35 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n < 1)
		return (0);
	while ((*s1 || *s2) && (*s1 == *s2) && (n > 1))
	{
		n--;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*int	main(void)
{
	char	*c = "abcdef5";
	char	*q = "abc1fgb";
	printf("%d \n", ft_strncmp(c, q, 7));
	printf("%d  \n", strncmp(c, q, 7));
	return (0);
}*/
