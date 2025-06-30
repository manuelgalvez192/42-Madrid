/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:50:47 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/30 17:49:56 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, const char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error allocating memory for data", 2), 1);
	if (!check_valid_input(argv))
		return (1);
	if (!init_data(data, argv))
		return (1);
	start_simulation(data);
	cleanup(data);
	return (0);
}
