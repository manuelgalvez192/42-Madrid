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

char	*check_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e' || arg[i - 3] != 'b'
		|| arg[i - 4] != '.')
	{
		ft_printf("Error\n de tipo de extension. Que acabe en .ber pls\n");
		return (NULL);
	}
	return (arg);
}
void	check_border(char **map)
{
	size_t	j;
	size_t	height;
	size_t	width;
	size_t	height_aux;

	j = 0;
	height = 0;
	height_aux = 0;
	width = ft_strlen(map[0]) - 1;
	while (map[height_aux] != NULL)
		height_aux++;
	while (map[height] != NULL)
	{
		if (height == height_aux)
			width++;
		if (map[height][0] != '1')
		{
			printf("Error\n los bordes no son correctos\n");
			free_map(map);
			*map = NULL;
			exit(0);
		}
		if (map[height][width - 1] != '1')
		{
			printf("Error\n los bordes no son correctos\n");
			free_map(map);
			*map = NULL;
			exit(0);
		}
		height++;
	}
	check_border_side(map, height, j);
}

void	check_border_side(char **map, size_t height, size_t j)
{
	while (map[0][j] != '\n')
	{
		if (map[0][j] != '1')
		{
			printf("Error\n los bordes no son correctos\n");
			free_map(map);
			*map = NULL;
			exit(0);
		}
		if (map[height - 1][j] != '1')
		{
			printf("Error\n los bordes no son correctos\n");
			free_map(map);
			*map = NULL;
			exit(0);
		}
		j++;
	}
}
