/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:55:24 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/01 20:29:16 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_vars *vars, mlx_t	*mlx)
{
	mlx_texture_t *texture;
	mlx_image_t *img;
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
			{
				texture = mlx_load_png("./sprites/murillo.png");
				img = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, img, i * 64, j * 64);
				mlx_set_instance_depth(&img->instances[0], 1);
			}	
			else if (vars->map[i][j] == '0')
			{
				texture = mlx_load_png("./sprites/fondo.png");
				img = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, img, i * 64, j * 64);
				mlx_set_instance_depth(&img->instances[0], 1);
			}
			else
				put_other_images(mlx, vars->map[i][j], j, i);
			j++;
		}
		i++;
	}
}

void	put_other_images(mlx_t *mlx, char c, int i, int j)
{
	mlx_texture_t *texture;
	mlx_image_t *img;
	
	if (c == 'P')
	{	
		texture = mlx_load_png("./sprites/knight.png");
		img = mlx_texture_to_image(mlx, texture);
		mlx_image_to_window(mlx, img, i * 64, j * 64);
		mlx_set_instance_depth(&img->instances[0], 2);
		texture = mlx_load_png("./sprites/fondo.png");
		img = mlx_texture_to_image(mlx, texture);
		mlx_image_to_window(mlx, img, i * 64, j * 64);
		mlx_set_instance_depth(&img->instances[0], 1);
	}
	else if (c == 'E')
	{
		texture = mlx_load_png("./sprites/salida.png");
		img = mlx_texture_to_image(mlx, texture);
		mlx_image_to_window(mlx, img, i * 64, j * 64);
		mlx_set_instance_depth(&img->instances[0], 1);
	}
	else if (c == 'C')
	{
		texture = mlx_load_png("./sprites/recolectable.png");
		img = mlx_texture_to_image(mlx, texture);
		mlx_image_to_window(mlx, img, i * 64, j * 64);
		mlx_set_instance_depth(&img->instances[0], 1);
	}
}
