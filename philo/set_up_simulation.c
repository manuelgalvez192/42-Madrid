/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:08:41 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/01/30 16:55:34 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	set_up_simulation(t_data_philo *data)
{
	int	count;

	data->philo = malloc(sizeof(int) * data->num_of_philo);
	data->forks = malloc(sizeof(int) * data->num_of_philo);
	count = 1;
	while (count <= data->num_of_philo)
	{
		data->philo[count] = count;
		data->forks[count] = 1;	
	}
}
