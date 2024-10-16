/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:36:15 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/15 19:01:38 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_manager(t_vars vars)
{
	int		win_width;
	int		wind_height;

	vars.num_moves = 0;
	win_width = get_map_width(vars.map) * (64 - 2);
	wind_height = get_map_height(vars.map) * 64;
	vars.mlx = mlx_init(win_width, wind_height, "so_long", false);
	put_images(&vars);
	mlx_close_hook(vars.mlx, &close_window, &vars);
	mlx_key_hook(vars.mlx, &handle_keypress, &vars);
	mlx_loop(vars.mlx);
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

void	close_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	free_vars(vars);
	exit(0);
}
