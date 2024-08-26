/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:52:40 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/06/07 20:52:43 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"


/* --- struct --- */
typedef struct s_vars {
	void *mlx;
	void *win;
	void *wall_img;
	void *floor_img;
	void *player_img;
	void *exit_img;
	void *collectible_img;
} t_vars;


/* --- main functions --- */
char	**store_map(char **map, int fd);
char	**fill_map(int fd, char **map);


/* --- error_manager functions --- */
char	*check_size_map(char **map);
size_t	check_width_size(char **map, size_t width);
char	*check_chars(char **map);
void	count_and_validate_chars(char **map, int *count_p, int *count_e, int *count_c);


/* --- error_free functions --- */
char	*free_map(char **map);
char	*check_valid_file(int fd, char *argv);
char	*check_extension(char *arg);
void	check_border(char **map);
void	check_border_side(char **map, size_t height, size_t j);


/* --- game_manager functions --- */
void	game_manager(char **map);
int		close_window(char **map);


/* --- images_manager --- */
void    declare_images(t_vars vars, char** map);
void	put_images(t_vars vars, char **map);

#endif
