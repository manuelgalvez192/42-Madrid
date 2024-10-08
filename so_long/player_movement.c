/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:38:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/10 19:10:10 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_keypress(mlx_key_data_t keydata, void* param)
{
	t_vars *vars = (t_vars*)param;
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
		return;
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->map[new_y][new_x] = 'P';
	vars->player_x = new_x;
	vars->player_y = new_y;
	vars->player_img->instances[0].x = new_x * 64;
	vars->player_img->instances[0].y = new_y * 64;
	print_map(vars);
}

void print_map(t_vars *vars)
{
	int i, j;
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			// Print each character of the map
			printf("%c", vars->map[i][j]);
			j++;
		}
		// Move to the next line
		i++;
	}
	printf("\n");
	printf("\n");
}
