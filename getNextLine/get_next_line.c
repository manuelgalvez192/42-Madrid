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

int check_for_new_line(char *str)
{
    int count = 0;
    while(str[count++])
    {
        if(str[count] == '\n')
            return(1);
    }
    return(0);
}

char	*get_next_line(int fd)
{
    char    *buffer;
    char    *line = " ";
    char    *character;
    int return_val = 0;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    while(return_val != 6)
    {   
        line = ft_strjoin(line, buffer);
        read(fd, buffer, BUFFER_SIZE);
        return_val++;
        printf("%s", buffer);
    }
    printf("\n%s\n", line);
    return(buffer);
}
/*
    //
    line = malloc(sizeof(char *));
    //character = malloc(sizeof(char *));
    while(check_for_new_line(line) == 0)
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
        return_val = read(fd, buffer, BUFFER_SIZE);
        buffer[return_val] = '\0';
        line = ft_strjoin(line, buffer);
        free(buffer);
        //printf("%s\n", line);
    }
    return (line);
}
*/
/*      while(*buffer)
        {
            *character = *buffer;
            if(*character == '\n')
            {
                return (line);
            }
            printf("the line -> %s\n", line);
            buffer++;
        }
        line = ft_strjoin(line, character);
 */
