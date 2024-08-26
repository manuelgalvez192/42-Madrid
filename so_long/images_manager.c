/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:55:24 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/08/17 18:55:27 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    declare_images(t_vars vars, char** map)
{
    vars.wall_img = mlx_xpm_file_to_image(vars.mlx, "sprites/murillo.xpm", 13, 16);
    vars.floor_img = mlx_xpm_file_to_image(vars.mlx, "sprites/fondo.xpm", 13, 16);
    vars.player_img = mlx_xpm_file_to_image(vars.mlx, "sprites/knight.xpm", 13, 16);
    vars.collectible_img = mlx_xpm_file_to_image(vars.mlx, "sprites/recolectable.xpm", 13, 16);
    vars.exit_img = mlx_xpm_file_to_image(vars.mlx, "sprites/salida.xpm", 13, 16);
}

void	put_images(t_vars vars, char **map)
{
	int x;
    int y;
    int i;
    int j;

    i = 0;
    y = 0;
    while (map[i])
    {
        j = 0;
        x = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(vars.mlx, vars.win, vars.wall_img, x, y);
            else if (map[i][j] == '0')
                mlx_put_image_to_window(vars.mlx, vars.win, vars.floor_img, x, y);
            else if (map[i][j] == 'P')
                mlx_put_image_to_window(vars.mlx, vars.win, vars.player_img, x, y);
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(vars.mlx, vars.win, vars.exit_img, x, y);
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(vars.mlx, vars.win, vars.collectible_img, x, y);
            
            x += 13;
            j++;
        }
        y += 16;
        i++;
    }	
}
