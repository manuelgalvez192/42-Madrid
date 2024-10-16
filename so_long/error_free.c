/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:44:21 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/15 19:02:42 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_map(char **map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

char	*free_vars(t_vars *vars)
{
	if (vars->map != NULL)
		free_map(vars->map);
	if (vars->mlx)
		mlx_terminate(vars->mlx);
	return (NULL);
}

char	*check_valid_file(int fd, char *argv)
{
	if (fd == -1)
	{
		ft_printf("Error\n al abrir el archivo\n");
		exit(0);
	}
	if (check_extension(argv) == NULL)
		return (0);
	return (NULL);
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
		if (map[height][0] != '1' || map[height][width - 1] != '1')
		{
			ft_printf("Error\n los bordes no son correctos\n");
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
		if (map[0][j] != '1' || map[height - 1][j] != '1')
		{
			ft_printf("Error\n los bordes no son correctos\n");
			free_map(map);
			*map = NULL;
			exit(0);
		}
		j++;
	}
}
