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
		ft_printf("Error\n de mapa. No es un rectangulo\n");
		free_map(map);
		*map = NULL;
		exit(0);
	}
	if (width < 3 || height < 3)
	{
		ft_printf("Error\n de mapa. El mapa esta chikito\n");
		free_map(map);
		*map = NULL;
		exit(0);
	}
	return (NULL);
}

void count_and_validate_chars(char **map, int *count_p, int *count_e, int *count_c)
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
                && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')
            {
                printf("Error\n de caracteres %c en el mapa\n", map[i][j]);
                return (free_map(map), *map = NULL, 0);
            }
            if (map[i][j] == 'P')
                (*count_p)++;
            if (map[i][j] == 'E')
                (*count_e)++;
            if (map[i][j] == 'C')
                (*count_c)++;
            j++;
        }
        i++;
    }
}

char *check_chars(char **map)
{
    int count_p = 0;
    int count_e = 0;
    int count_c = 0;

    count_and_validate_chars(map, &count_p, &count_e, &count_c);

    if (map == NULL)
        return (0);

    if (count_p != 1 || count_e != 1 || count_c < 1)
    {
        if (count_p != 1)
            printf("Error\n el carácter 'P'. Comprueba cuantas veces sale\n");
        if (count_e != 1)
            printf("Error\n el carácter 'E'. Comprueba cuantas veces sale\n");
        if (count_c < 1)
            printf("Error\n el carácter 'C'. No hay coleccionables\n");
        free_map(map);
        *map = NULL;
        return (0);
    }

    return (NULL);
}
