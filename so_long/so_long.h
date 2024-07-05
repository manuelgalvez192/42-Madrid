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
# include <stdio.h>


/* --- main functions --- */
char	**store_map(char **map, int fd);
char	**fill_map(int fd, char **map);

/* --- error_manager functions --- */
char	*check_extension(char *arg);
char	*check_size_map(char **map);
size_t	check_width_size(char **map, size_t width);
void	count_and_validate_chars(char **map, int *count_p, int *count_e, int *count_c);
char	*check_chars(char **map);

/* --- error_free functions --- */
char	*free_map(char **map);
char	*check_valid_file(int fd, char *argv);

#endif
