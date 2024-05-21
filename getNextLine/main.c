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

int    main(void)
{
    char    *line;
    int     fd = open("file.txt", O_RDONLY);
    int i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        i++;
        printf("%s", line);
        free(line);
    }
    return (0);
}
