/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:23:09 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/04/26 20:37:46 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDONLY);

    char *line;
    while (1) 
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        if(!line[0])
            break;
        printf("%s", line);
        free (line);
    }
    close(fd);
    return 0;
}
