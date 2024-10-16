/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:48:34 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/10/16 20:02:08 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_valid_file(fd, argv[1]);
		vars.map = NULL;
		vars.map = store_map(vars.map, fd);
		fd = open(argv[1], O_RDONLY);
		vars.map = fill_map(fd, &vars);
		check_size_map(vars.map);
		check_chars(vars.map);
		if (!verify_access(&vars))
		{
			ft_printf("Error\n No se puede acceder a ciertos elementos.\n");
			free_map(vars.map);
			exit(0);
		}
		game_manager(vars);
		free_vars(&vars);
		if (vars.map == NULL)
			return (0);
		close(fd);
	}
	else
		ft_printf("Error\n del numero de parametros. Pon un parametro pls\n");
	return (0);
}

char	**store_map(char **map, int fd)
{
	char	*line;
	int		width;
	int		height;
	int		i;

	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\n de mapa. El mapa esta vacio\n");
		exit(0);
	}
	width = ft_strlen(line);
	height = 0;
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	map = ft_calloc(sizeof(char *), height + 1);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = ft_calloc(sizeof(char *), width + 1);
		if (map[i++] == NULL)
			return (NULL);
	}
	return (close(fd), map);
}

char	**fill_map(int fd, t_vars *vars)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	vars->num_collectibles = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		j = 0;
		while (line[j] != '\0')
		{
			vars->map[i][j] = line[j];
			if (vars->map[i][j] == 'P')
			{
				vars->player_x = j;
				vars->player_y = i;
			}
			else if (vars->map[i][j] == 'C')
				vars->num_collectibles++;
			j++;
		}
		vars->map[i][j] = '\0';
		free(line);
		line = NULL;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (vars->map);
}

char	*check_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e' || arg[i - 3] != 'b'
		|| arg[i - 4] != '.')
	{
		ft_printf("Error\n de tipo de extension. Que acabe en .ber pls\n");
		exit(0);
	}
	return (arg);
}
