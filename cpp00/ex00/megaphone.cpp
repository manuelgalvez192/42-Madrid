/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:22:41 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/07/16 19:42:54 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>

int main(int argc, char **argv)
{
    int i = 1;
    char c;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
        
    while (i < argc)
    {    
        for (int j = 0; argv[i][j]; j++)
        {
            c = argv[i][j];
            if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                c = (char)std::toupper(argv[i][j]);
            std::cout << c;
        }
        i++; 
    }
    std::cout << std::endl;
    return 0;
}
