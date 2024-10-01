/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:36:15 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/01 19:39:50 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_manager(t_vars vars)
{
	int		win_width;
	int		wind_height;
	mlx_t	*mlx;

	win_width = get_map_width(vars.map) * (64 - 2);
	wind_height = get_map_height(vars.map) * 64;
	mlx = mlx_init(win_width, wind_height, "so_long", false);
	
	mlx_loop(mlx);
}

int	get_map_width(char **map)
{
	if (map[0] == NULL)
		return (0);
	return (ft_strlen(map[0]));
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}
