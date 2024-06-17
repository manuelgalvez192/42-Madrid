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
		perror("Error\n al abrir el archivo\n");
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
		perror("Error\n de tipo de extension. Que acabe en .ber pls\n");
		return (NULL);
	}
	return (arg);
}

char	*check_size_map(char **map)
{
	int		width;
	int		height;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height] != NULL)
		height++;
	if ((width - 1)  == height)
	{
		perror("Error\n de mapa. No es un rectangulo\n");
		return (0);
	}
	if (width < 3 || height < 3)
	{
		perror("Error\n de mapa. El mapa esta chikito\n");
		return (0);
	}
	return (NULL);
}

char	*check_chars(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
			{
				perror("Error\n Caracter no valido\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
