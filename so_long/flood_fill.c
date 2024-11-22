/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:41:02 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/11 18:59:26 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**clone_map(char **map)
{
	char	**new_map;
	int		i;
	int		rows;

	rows = ft_strlen(*map);
	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	flood_fill(char **map, t_flood_data *data, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1' ||
		map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		data->has_exit = true;
		return ;
	}
	if (map[y][x] == 'C')
		data->collectibles_count++;
	map[y][x] = 'V';
	flood_fill(map, data, x + 1, y);
	flood_fill(map, data, x - 1, y);
	flood_fill(map, data, x, y + 1);
	flood_fill(map, data, x, y - 1);
}

void	locate_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

bool	verify_access(t_vars *vars)
{
	char			**map_clone;
	t_flood_data	data;
	int				i;
	int				j;

	map_clone = clone_map(vars->map);
	if (!map_clone)
		return (false);
	data.total_collectibles = 0;
	data.collectibles_count = 0;
	data.has_exit = false;
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'C')
				data.total_collectibles++;
		}
	}
	locate_position(vars->map, &data.start_x, &data.start_y);
	flood_fill(map_clone, &data, data.start_x, data.start_y);
	return (free_map(map_clone),
		data.has_exit && data.collectibles_count == data.total_collectibles);
}

void	call_floodfill(t_vars vars)
{
	if (!verify_access(&vars))
	{
		ft_printf("Error\n No se puede acceder a ciertos elementos.\n");
		free_map(vars.map);
		exit(0);
	}
}
