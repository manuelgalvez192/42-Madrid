/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:36:15 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/09/28 17:27:52 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_manager(t_vars vars)
{
	int		win_width;
	int		wind_height;

	win_width = get_map_width(vars.map) * (64 - 2);
	wind_height = get_map_height(vars.map) * 64;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, win_width, wind_height, "so_long");
	mlx_hook(vars.win, 17, 0L, close_window, &vars);
	declare_images(&vars);
	put_images(&vars);
	mlx_loop(vars.mlx);
}

int	get_map_width(char **map)
{
	if (map[0] == NULL)
		return (0);
	return (strlen(map[0]));
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	close_window(t_vars *vars)
{
	free_map(vars->map);
	free_vars(vars);
	exit(0);
	return (0);
}
