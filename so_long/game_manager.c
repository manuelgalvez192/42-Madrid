/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:36:15 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/06/07 21:36:16 by mgalvez-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_manager(char **map)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
    mlx_hook(vars.win, 17, 0L, close_window, map);
    mlx_loop(vars.mlx);
    declare_images(vars, map);
    put_images(vars, map);
}

int close_window(char **map)
{
    free_map(map);
    exit(0);
    return (0);
}