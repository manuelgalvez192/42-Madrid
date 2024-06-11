/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:43:54 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/06/07 21:43:56 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_valid_file(int fd, char *argv)
{
	if (fd == -1)
	{
		perror("Error al abrir el archivo\n");
		return (0);
	}
	if (check_extension(argv) == NULL)
		return (0);
	return (NULL);
}

char	*check_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e' || arg[i - 3] != 'b'
		|| arg[i - 4] != '.')
	{
		perror("Error de tipo de extension. Que acabe en .ber pls\n");
		return (NULL);
	}
	return (arg);
}
