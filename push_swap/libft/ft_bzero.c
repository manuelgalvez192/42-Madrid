/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:35:09 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/01/26 20:15:52 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)c)[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char c[5] = "aaaa";
	char q[5] = "aaaa";
	ft_bzero(c, 3);
	printf("%s \n", c);
	bzero(q, 3);
	printf("%s \n", q);
	return (0);
}*/
