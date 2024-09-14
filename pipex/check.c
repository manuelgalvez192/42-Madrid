/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:39:00 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/09/14 20:32:27 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_cmd(char **envp, char **argv, int index)
{
	char	**split_path;
	char	*path;
	int		i;

	while (index != 4)
	{
		i = path_finder(envp);
		split_path = ft_split(envp[i], ':');
		path = locate_path(split_path, argv[index]);
		if (path == NULL)
			return (1);
		index++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = size * count;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	while (len > 0)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
		len--;
	}
	return ((unsigned char *)ptr);
}
