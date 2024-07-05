/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:44:21 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/06/18 19:44:22 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

char	*check_valid_file(int fd, char *argv)
{
	if (fd == -1)
	{
		ft_printf("Error\n al abrir el archivo\n");
		return (0);
	}
	if (check_extension(argv) == NULL)
		return (0);
	return (NULL);
}
