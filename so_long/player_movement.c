/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:38:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/16 19:59:40 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(vars, vars->player_x, vars->player_y - 1);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(vars, vars->player_x - 1, vars->player_y);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(vars, vars->player_x, vars->player_y + 1);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(vars, vars->player_x + 1, vars->player_y);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(vars);
	return ;
}

void	move_player(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] == '1')
		return ;
	if (vars->map[new_y][new_x] == 'C')
	{
		vars->num_collectibles--;
		vars->depth = 2;
		put_image_to_window(vars, "./sprites/fondo.png", new_x, new_y);
	}
	if (vars->map[new_y][new_x] == 'E' && vars->num_collectibles == 0)
	{
		ft_printf("You win!\n");
		close_window(vars);
	}
	if (vars->map[new_y][new_x] != 'E')
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->map[new_y][new_x] = 'P';
		vars->player_x = new_x;
		vars->player_y = new_y;
		vars->player_img->instances[0].x = new_x * 64;
		vars->player_img->instances[0].y = new_y * 64;
		ft_printf("Numero de movimientos: %d\n", ++vars->num_moves);
	}
}
