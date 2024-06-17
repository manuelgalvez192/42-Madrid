/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:48:34 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/06/07 20:48:36 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_valid_file(fd, argv[1]);
		map = store_map(fd);
		fd = open(argv[1], O_RDONLY);
		map = fill_map(fd, map);
		check_size_map(map);
		check_chars(map);
		free (map);
		if (map == NULL)
			return (0);
		close(fd);
	}
	else
		perror("Error\n del numero de parametros. Pon un parametro pls\n");
	return (0);
}

char	**store_map(int fd)
{
	char	**map;
	int		width;
	int		height;
	int		i;

	width = ft_strlen(get_next_line(fd));
	height = 1;
	while (get_next_line(fd) != NULL)
		height++;
	map = ft_calloc(sizeof(char *), height + 1);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = ft_calloc(sizeof(char *), width + 1);
		if (map[i] == NULL)
			return (NULL);
		i++;
	}
	close(fd);
	return (map);
}

char	**fill_map(int fd, char **map)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		j = 0;
		while (line[j] != '\0')
		{
			map[i][j] = line[j];
			j++;
		}
		i++;
	}
	close(fd);
	return (map);
}
