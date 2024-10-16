/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:55:24 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/16 20:00:39 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
			{
				vars->depth = 1;
				put_image_to_window(vars, "./sprites/murillo.png", j, i);
			}
			else if (vars->map[i][j] == '0')
			{
				vars->depth = 1;
				put_image_to_window(vars, "./sprites/fondo.png", j, i);
			}
			else
				put_other_images(vars, i, j);
			j++;
		}
	}
}

void	put_other_images(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'P')
	{
		vars->depth = 3;
		vars->player_img = put_image_to_window(vars,
				"./sprites/knight.png", j, i);
		vars->depth = 1;
		put_image_to_window(vars, "./sprites/fondo.png", j, i);
	}
	else if (vars->map[i][j] == 'E')
	{
		vars->depth = 1;
		put_image_to_window(vars, "./sprites/salida.png", j, i);
	}
	else if (vars->map[i][j] == 'C')
	{
		vars->depth = 1;
		put_image_to_window(vars, "./sprites/recolectable.png", j, i);
	}
}

mlx_image_t	*put_image_to_window(t_vars *vars, char *file_path, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(file_path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(vars->mlx, texture);
	if (!img)
	{
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_image_to_window(vars->mlx, img, x * 64, y * 64);
	mlx_set_instance_depth(&img->instances[0], vars->depth);
	mlx_delete_texture(texture);
	return (img);
}
