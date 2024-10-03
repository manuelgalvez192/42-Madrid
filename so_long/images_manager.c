/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:55:24 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/03 19:31:45 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_vars *vars)
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
				img = mlx_texture_to_image(vars->mlx, texture);
				mlx_image_to_window(vars->mlx, img, j * 64, i * 64);
				mlx_set_instance_depth(&img->instances[0], 1);
				mlx_delete_texture(texture);
			}	
			else if (vars->map[i][j] == '0')
			{
				texture = mlx_load_png("./sprites/fondo.png");
				img = mlx_texture_to_image(vars->mlx, texture);
				mlx_image_to_window(vars->mlx, img, j * 64, i * 64);
				mlx_set_instance_depth(&img->instances[0], 1);
				mlx_delete_texture(texture);
			}
			else
				put_other_images(vars, vars->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	put_other_images(t_vars *vars, char c, int i, int j)
{
	mlx_texture_t *texture;
	mlx_image_t *img;
	
	if (c == 'P')
	{	
		texture = mlx_load_png("./sprites/knight.png");
		img = mlx_texture_to_image(vars->mlx, texture);
		mlx_image_to_window(vars->mlx, img, j * 64, i * 64);
		vars->player_img = img;
		mlx_delete_texture(texture);
		mlx_set_instance_depth(&img->instances[0], 2);
		texture = mlx_load_png("./sprites/fondo.png");
		img = mlx_texture_to_image(vars->mlx, texture);
		mlx_image_to_window(vars->mlx, img, j * 64, i * 64);
		mlx_set_instance_depth(&img->instances[0], 1);
		mlx_delete_texture(texture);
	}
	else if (c == 'E')
	{
		texture = mlx_load_png("./sprites/salida.png");
		img = mlx_texture_to_image(vars->mlx, texture);
		mlx_image_to_window(vars->mlx, img, j * 64, i * 64);
		mlx_set_instance_depth(&img->instances[0], 1);
		mlx_delete_texture(texture);
	}
	else if (c == 'C')
	{
		texture = mlx_load_png("./sprites/recolectable.png");
		img = mlx_texture_to_image(vars->mlx, texture);
		mlx_image_to_window(vars->mlx, img, j * 64, i * 64);
		mlx_set_instance_depth(&img->instances[0], 1);
		mlx_delete_texture(texture);
	}
}
