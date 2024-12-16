/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:49:59 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/12/16 18:59:30 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *c, int a, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)c)[i] = (unsigned char)a;
		i++;
	}
	return (c);
}
