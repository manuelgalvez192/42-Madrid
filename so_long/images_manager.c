/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:55:24 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/09/28 17:31:40 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	declare_images(t_vars *vars)
{
	int	width;
	int	height;

	vars->wall_img = mlx_xpm_file_to_image(vars->mlx,
			"sprites/murillo.xpm", &width, &height);
	vars->floor_img = mlx_xpm_file_to_image(vars->mlx,
			"sprites/fondo.xpm", &width, &height);
	vars->player_img = mlx_xpm_file_to_image(vars->mlx,
			"sprites/knight.xpm", &width, &height);
	vars->collectible_img = mlx_xpm_file_to_image(vars->mlx,
			"sprites/recolectable.xpm", &width, &height);
	vars->exit_img = mlx_xpm_file_to_image(vars->mlx,
			"sprites/salida.xpm", &width, &height);
}

void	put_images(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->wall_img, j * 64, i * 64);
			else if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->floor_img, j * 64, i * 64);
			else
				put_other_images(vars, vars->map[i][j], j, i);
			j++;
		}
		i++;
	}
}

void	put_other_images(t_vars *vars, char c, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player_img, x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit_img, x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->collectible_img, x * 64, y * 64);
}
