/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:52:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/09/28 19:46:58 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <stdbool.h>


/* --- struct --- */
typedef struct s_vars {
	char **map;
	void *mlx;
	void *win;
	void *wall_img;
	void *floor_img;
	void *player_img;
	void *exit_img;
	void *collectible_img;
} t_vars;

typedef struct s_flood_data {
	bool	has_exit;
	int		collectibles_count;
	int		total_collectibles;
	int		start_x;
	int		start_y;
} t_flood_data;


/* --- main functions --- */
char	**store_map(char **map, int fd);
char	**fill_map(int fd, char **map);
char	*check_extension(char *arg);


/* --- error_manager functions --- */
char	*check_size_map(char **map);
size_t	check_width_size(char **map, size_t width);
char	*check_chars(char **map);
void	count_and_validate_chars(char **map, int *count_p, int *count_e, int *count_c);


/* --- error_free functions --- */
char	*free_map(char **map);
char	*free_vars(t_vars *vars);
char	*check_valid_file(int fd, char *argv);
void	check_border(char **map);
void	check_border_side(char **map, size_t height, size_t j);


/* --- game_manager functions --- */
void	game_manager(t_vars vars);
int		get_map_width(char **map);
int		get_map_height(char **map);
int		close_window(t_vars *vars);


/* --- images_manager --- */
void	declare_images(t_vars *vars);
void	put_images(t_vars *vars);
void	put_other_images(t_vars *vars, char c, int x, int y);


/* --- flood_fill --- */
char	**clone_map(char **map);
void	flood_fill(char **map, t_flood_data *data, int x, int y);
void	locate_position(char **map, int *x, int *y);
bool	verify_access(t_vars *vars);

#endif
