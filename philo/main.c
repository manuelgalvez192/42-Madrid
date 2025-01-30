/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:50:47 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/30 16:55:06 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_data_philo	*data;

	if (argc != 5 && argc != 6)
	{
		ft_printf("Error: wrong number of arguments\n");
		return (1);
	}
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc = 6)
		data->must_eat = ft_atoi(argv[5]);
	set_up_simulation(data);
	start_simulation(data);
}
