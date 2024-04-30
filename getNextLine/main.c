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

int    main(int argc, char **argv)
{
    (void)argc;
    char *line;

    int fd = open(argv[1], O_RDONLY);
    line = "1";
    while(line)
        printf("%s", line);
    {
        line = get_next_line(fd);
    }
    system("leaks a.out");
    close(fd);
    return (0);
}
