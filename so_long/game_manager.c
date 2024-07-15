/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:36:15 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/06/07 21:36:16 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_manager(char **map)
{
	void	*mlx;
	void	*window;

	*map = NULL;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "so_long");
	mlx_hook(window, 17, 0L, close_window, window);
	mlx_loop(mlx);
}

int	close_window(void *window)
{
	mlx_destroy_window(window, window);
	exit(0);
}