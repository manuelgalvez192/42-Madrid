/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:17:36 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/04/08 19:41:17 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char    *buffer;
    char    *line;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    line = malloc(sizeof(char *));
    while(read(fd, buffer, BUFFER_SIZE))
    {
        while(*buffer)
        {
            if(*buffer == '\n')
            {
                printf("yes\n");
                line = ft_strjoin(line, buffer);
                return (line);
            }
            buffer++;
        }
        line = ft_strjoin(line, buffer);
    }
    return (line);
}
