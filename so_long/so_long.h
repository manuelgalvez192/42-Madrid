/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:52:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/14 15:34:52 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>

/* --- struct --- */
typedef struct s_vars
{
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	int			num_collectibles;
	int			num_moves;
	int			player_x;
	int			player_y;
	int			depth;
}	t_vars;

typedef struct s_flood_data
{
	bool	has_exit;
	int		collectibles_count;
	int		total_collectibles;
	int		start_x;
	int		start_y;
}	t_flood_data;

/* --- main functions --- */
char		**store_map(char **map, int fd);
char		**store_map_aux(char **map, int width, int height);
char		**fill_map(int fd, t_vars *vars);
void		fill_map_aux(t_vars *vars, int i, char *line);

/* --- error_manager functions --- */
char		*check_size_map(char **map);
size_t		check_width_size(char **map, size_t width);
char		*check_chars(char **map);
void		count_and_validate_chars(char **map, int *count_p,
				int *count_e, int *count_c);
char		*check_extension(char *arg);

/* --- error_free functions --- */
char		*free_map(char **map);
char		*free_vars(t_vars *vars);
char		*check_valid_file(int fd, char *argv);
void		check_border(char **map);
void		check_border_side(char **map, size_t height, size_t j);

/* --- game_manager functions --- */
void		game_manager(t_vars vars);
int			get_map_width(char **map);
int			get_map_height(char **map);
void		close_window(void *param);

/* --- images_manager --- */
void		put_images(t_vars *vars);
void		put_other_images(t_vars *vars, int i, int j);
mlx_image_t	*put_image_to_window(t_vars *vars, char *file_path, int x, int y);

/* --- player_movement --- */
void		handle_keypress(mlx_key_data_t keydata, void *param);
void		move_player(t_vars *vars, int new_x, int new_y);

/* --- flood_fill --- */
char		**clone_map(char **map);
void		flood_fill(char **map, t_flood_data *data, int x, int y);
void		locate_position(char **map, int *x, int *y);
bool		verify_access(t_vars *vars);
void		call_floodfill(t_vars vars);

#endif
