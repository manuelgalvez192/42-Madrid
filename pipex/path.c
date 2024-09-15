/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:39:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/09/14 19:36:16 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	path_finder(char **envp)
{
	int	i;
	

	i = 0;
	while (envp[i])
	{
		if (envp[i])
		{
			if (envp[i][0] == 'P' && envp[i][1] == 'A'
				&& envp[i][2] == 'T' && envp[i][3] == 'H')
				return (i);
		}
		i++;
	}
	return (0);
}

char	*locate_path(char **split_path, char *cmd)
{
	int		i;
	int		flag_acss;
	char	*path;

	i = 0;
	while (split_path[i])
	{
		path = make_path(split_path[i], cmd);
		flag_acss = access(path, O_RDONLY);
		if (flag_acss == 0)
			return (path);
		else
		{
			free(path);
			i++;
		}
	}
	flag_acss = access(cmd, O_RDONLY);
	if (flag_acss == 0)
		return (cmd);
	return (NULL);
}

char	*make_path(char *split_path, char *cmd)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	path = malloc(ft_strlen(split_path) + ft_strlen(cmd + 1)
			+ 2 * sizeof(char));
	if (!path)
		return (NULL);
	while (split_path[i])
	{
		path[i] = split_path[i];
		i++;
	}
	path[i] = '/';
	i++;
	j = 0;
	while (cmd[j] && cmd[j]!= ' ')
	{
		path[i] = cmd[j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}
