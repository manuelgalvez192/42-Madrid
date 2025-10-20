/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:02:26 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/10/21 00:02:26 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main() {
	ClapTrap clap1("Clapete");
	ClapTrap clap2("Tramposa");

	clap1.attack("Tramposa");
	clap2.takeDamage(7);
	//clap2.takeDamage(7);
	//clap2.takeDamage(7);

	clap2.attack("Trampera");
	clap1.takeDamage(0);

	clap1.beRepaired(5);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);
	
	return 0;
}