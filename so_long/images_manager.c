/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:55:24 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/10 19:21:22 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				put_image_to_window(vars, "./sprites/murillo.png", j, i, 1);
			else if (vars->map[i][j] == '0')
				put_image_to_window(vars, "./sprites/fondo.png", j, i, 1);
			else	if (vars->map[i][j] == 'P')
			{
				vars->player_img = put_image_to_window(vars, "./sprites/knight.png", j, i, 2);
				put_image_to_window(vars, "./sprites/fondo.png", j, i, 1);
			}
			else if (vars->map[i][j] == 'E')
				put_image_to_window(vars, "./sprites/salida.png", j, i, 1);
			else if (vars->map[i][j] == 'C')
				put_image_to_window(vars, "./sprites/recolectable.png", j, i, 1);
			j++;
		}
		i++;
	}
}

mlx_image_t	*put_image_to_window(t_vars *vars, char *file_path, int x, int y, int depth)
{
	mlx_texture_t *texture;
	mlx_image_t *img;

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
	mlx_set_instance_depth(&img->instances[0], depth);
	mlx_delete_texture(texture);
	return (img);
}
