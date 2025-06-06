/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:43:54 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/21 20:20:26 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_size_map(char **map)
{
	size_t	width;
	size_t	height;

	if (!map || !map[0])
	{
		ft_printf("Error\n de mapa. El mapa esta vacio\n");
		free_map(map);
		exit(0);
	}
	width = ft_strlen(map[0]) - 1;
	height = check_width_size(map, width);
	if (width < 3 || height < 3)
	{
		ft_printf("Error\n de mapa. El mapa esta chikito\n");
		free_map(map);
		exit(0);
	}
	return (NULL);
}

size_t	check_width_size(char **map, size_t width)
{
	size_t	height;
	size_t	height_aux;
	size_t	width_aux;

	height_aux = 0;
	while (map[height_aux] != NULL)
		height_aux++;
	height = 0;
	while (map[height] != NULL)
	{
		width_aux = ft_strlen(map[height]) - 1;
		height++;
		if (height_aux == height)
			width_aux++;
		if (width_aux != width)
		{
			ft_printf("Error\n de mapa. Los lados no miden lo mismo\n");
			free_map(map);
			exit(0);
		}
	}
	return (height);
}

char	*check_chars(char **map)
{
	int	count_p;
	int	count_e;
	int	count_c;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	count_and_validate_chars(map, &count_p, &count_e, &count_c);
	check_border(map);
	if (map == NULL)
		return (0);
	check_border(map);
	if (count_p != 1 || count_e != 1 || count_c < 1)
	{
		if (count_p != 1)
			ft_printf("Error\n el carácter 'P.\n");
		if (count_e != 1)
			ft_printf("Error\n el carácter 'E'.\n");
		if (count_c < 1)
			ft_printf("Error\n el carácter 'C'.\n");
		free_map(map);
		exit(0);
	}
	return (NULL);
}

void	count_and_validate_chars(char **map, int *count_p, int *count_e,
	int *count_c)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')
			{
				ft_printf("Error\n de caracteres %c en el mapa\n", map[i][j]);
				free_map(map);
				exit(0);
			}
			if (map[i][j] == 'P')
				(*count_p)++;
			if (map[i][j] == 'E')
				(*count_e)++;
			if (map[i][j] == 'C')
				(*count_c)++;
		}
	}
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
		exit(0);
	}
	return (arg);
}
